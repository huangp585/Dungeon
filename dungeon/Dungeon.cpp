#include"Dungeon.h"

Dungeon::Dungeon(){
}

void Dungeon::createPlayer() {
	this->player.setTag("player");
	this->player.setMaxHealth(100);
	this->player.setCurrentHealth(100);
	this->player.setAttack(30);
	this->player.setDefense(0);
}

void Dungeon::createMap() {
	Room* room0 = new Room();
	Room* room1 = new Room();
	Room* room2 = new Room();
	Room* room3 = new Room();
	Room* room4 = new Room();

	room0->setUpnDownRoom(room1);
	room1->setRightnLeftRoom(room2);
	room3->setUpnDownRoom(room2);
	room3->setRightnLeftRoom(room4);

	//add things to rooms
	vector<Item> v0, v1,v2;

	//v0 vector's item--chest0
	v0.push_back(Item("magic powder", 20, 0, 10));
	v0.push_back(Item("muscle pill", 0, 40, 0));
	v0.push_back(Item("shield", 0, 0, 50));
	NPC* room0_chest=new NPC("chest", "hwalalala a chest has been opened!", v0);

	//v1 vector's item--chest1
	v1.push_back(Item("rose", 0, 100, 0));
	v1.push_back(Item("wig", 0, 0, 80));
	v1.push_back(Item("honey", 150, 0, 50));
	NPC* room3_chest=new NPC("chest", "hwalalala a chest has been opened!", v1);

	//v2 vector's item--shop
	v2.push_back(Item("bread", 20, 0, 0));
	v2.push_back(Item("meat", 0, 40, 0));
	v2.push_back(Item("herb", 0, 0, 30));
	NPC* room2_Shop=new NPC("shop", "hi! how's your day! do you want to get something ?", v2);

	Monster* room1_monster=new Monster("Gik", 60, 20, 40);
	Monster* boss=new Monster("Shelby", 1000, 100, 50);

	room0->triggerEvent(room0_chest);
	room3->triggerEvent(room3_chest);
	room2->triggerEvent(room2_Shop);
	room1->triggerEvent(room1_monster);
	room4->triggerEvent(boss);

	rooms.push_back(room0);
	rooms.push_back(room1);
	rooms.push_back(room2);
	rooms.push_back(room3);
	rooms.push_back(room4);

	for (int i = 0; i <= 4; i++) {
		if (i == 4) {
			rooms[i]->setIsExit(true);
		}
		else {
			rooms[i]->setIsExit(false);
		}
		rooms[i]->setName("Room" + to_string(i));
		rooms[i]->setTag("Room");
		rooms[i]->setIndex(i);
	}
}

void Dungeon::handleMovement() {
	cout << "\nwhere do you want to go ?" << endl;
	Room* currentRoom = player.getCurrentRoom();
	Room* previousRoom = player.getPreviousRoom();
	char a;
	int i1 = -1, i2 = -1, i3 = -1, i4 = -1;
	for (int i = 0; i < 4; i++) {
		a = 'a' + i;
		if (currentRoom->getDownRoom() != NULL && i1 == -1) {
			cout << a << ". " << "go down" << endl;
			i1 = i;
			continue;
		}
		if (currentRoom->getUpRoom() != NULL && i2 == -1) {
			cout << a << ". " << "go up" << endl;
			i2 = i;
			continue;
		}
		if (currentRoom->getRightRoom() != NULL && i3 == -1) {
			cout << a << ". " << "go right" << endl;
			i3 = i;
			continue;
		}
		if (currentRoom->getLeftRoom() != NULL && i4 == -1) {
			cout << a << ". " << "go left" << endl;
			i4 = i;
			continue;	
		}
	}

	char choice;
	cin >> choice;
	mciSendString(TEXT("open move.wma alias mysong"), NULL, 0, NULL);
	mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//打开报警音
	Sleep(2000);
	mciSendString(TEXT("close mysong"), NULL, 0, NULL);//关闭报警音
	previousRoom = currentRoom;

	for (int i = 0; i < 4; i++) {
		if (((choice == 'a'+i)|| (choice == 'A' + i)) && i1 == i) {
			currentRoom = currentRoom->getDownRoom();
			break;
		}
		if (((choice == 'a' + i) || (choice == 'A' + i)) && i2 == i) {
			currentRoom = currentRoom->getUpRoom();
			break;
		}
		if (((choice == 'a' + i) || (choice == 'A' + i)) && i3 == i) {
			currentRoom = currentRoom->getRightRoom();
			break;
		}
		if (((choice == 'a' + i) || (choice == 'A' + i)) && i4 == i) {
			currentRoom = currentRoom->getLeftRoom();
			break;
		}
	}
	player.setPreviousRoom(previousRoom);
	player.setCurrentRoom(currentRoom);
}
                                
bool Dungeon::handleEvent(Object* _object) {
	Player* _player = dynamic_cast<Player*>(_object);
	if (_player != NULL) {
		player.triggerEvent(&player);
		return false;
	}
	NPC* npc = dynamic_cast<NPC*>(_object);
	if (npc != NULL) {
		npc->triggerEvent(&player);
		if (npc->getCommodity().size() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	Monster* monster = dynamic_cast<Monster*>(_object);
	if(monster!=NULL){
		monster->triggerEvent(&player);
		return true;
	}
}

void Dungeon::startGame() {
	this->createPlayer();
	this->createMap();
}


bool Dungeon::checkGameLogic() {
	Room* currentRoom = player.getCurrentRoom();
	if (currentRoom->getIsExit() && !player.checkIsDead()) {
		return true;
	}
	else if (player.checkIsDead()) {
		return false;
	}
}

							
void Dungeon::chooseAction(Room* _room) {
	cout << "\nWhat do you want to do ? " << endl;

	int index = -1;
	int a = 0;
	vector<Object*> objects;
	char choice;
	char in = 'A' + a;
	int npc = 0;

	//case 1
	for (int i = 0; i < _room->getObjects().size(); i++) {
		objects = _room->getObjects();
		if ( objects[i]->getName()== "chest") {
			cout << in << ". " << "Open the Chest" << endl;
			npc = 1;
			a++;
		}
		else if(objects[i]->getName()=="shop"){
			cout << in << ". " << "Talk to Shop" << endl;
			npc = 1;
			a++;
		}
		index = i;
	}
	in = 'A' + a;
	cout << in << ". " << "Check Status" << endl;
	a++;
	in = 'A' + a;
	cout << in << ". " << "Move" << endl;
	a++;
	in = 'A' + a;
	cout << in << ". " << "Save to File" << endl;

	cin >> choice;
	if (npc != 1) {
		choice++;
	}
	switch (choice) {
	case 'A': case'a':
		objects = _room->getObjects();
		if (handleEvent(objects[index])) {
			_room->deleteObject(objects[index]);
			//_room->getObjects().erase((_room->getObjects()).begin() + index);
		}
		break;
	case'B':case'b':
		handleEvent(&player);
		break;
	case'C':case'c':
		handleMovement();
		break;
	case'D':case'd':
		Record record;
		record.saveToFile(&player, rooms);
		break;
		//save
	}
}

void Dungeon::runDungeon() {
	startGame();//create player and map
	Room* room = NULL;
	player.setCurrentRoom(rooms[0]);
	int into_room4 = 0;//room[1] and room[4]4

	//load previous data
	char choice;
	cout << "Do you want to load previous data ?\na. yes\nb. No, start new game." << endl;
	cin >> choice;

	if (choice == 'a'||choice=='A') {
		Record record;
		record.loadFromFile(&player,rooms);
	}
	else {
		cout << "please enter player's name : ";
		string _name;
		cin >> _name;
		player.setName(_name);
	}

	while (1) {
		room = player.getCurrentRoom();
		if (rooms[1]->getObjects().size()!=0 && room == rooms[1]){ 
			Monster* monster = new Monster();
			monster->setTag("Monster");
			monster = dynamic_cast<Monster*>(room->popObject(monster));
			mciSendString(TEXT("open monster.wma alias mysong"), NULL, 0, NULL);
			mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//打开报警音
			Sleep(5000);
			mciSendString(TEXT("close mysong"), NULL, 0, NULL);//关闭报警音
			bool check = monster->triggerEvent(&player);
			int index = player.getCurrentRoom()->getIndex();
			if (!check&&index==1) {
				cout << "Game over, you lose" << endl;
				mciSendString(TEXT("open lose.wma alias mysong"), NULL, 0, NULL);
				mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//打开报警音
				Sleep(2000);
				mciSendString(TEXT("close mysong"), NULL, 0, NULL);//关闭报警音
				exit(0);
			}
			else if(check&&index==1){
				cout << "\nYou beat " << monster->getName() << " !" << endl;
				mciSendString(TEXT("open cheer.wma alias mysong"), NULL, 0, NULL);
				mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//打开报警音
				Sleep(2000);
				mciSendString(TEXT("close mysong"), NULL, 0, NULL);//关闭报警音
				rooms[1]->deleteObject(monster);
			}
			else {
				continue;
			}
		}
		else if (room == rooms[4]) {
			Monster* monster = new Monster();
			monster->setTag("Monster");
			monster = dynamic_cast<Monster*>(room->popObject(monster));
			mciSendString(TEXT("open boss.wma alias mysong"), NULL, 0, NULL);
			mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//打开报警音
			Sleep(6000);
			mciSendString(TEXT("close mysong"), NULL, 0, NULL);//关闭报警音
			bool check = monster->triggerEvent(&player);
			if (checkGameLogic()&&check) {
				cout << "Victory!" << endl;
				mciSendString(TEXT("open cheer.wma alias mysong"), NULL, 0, NULL);
				mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//打开报警音
				Sleep(2000);
				mciSendString(TEXT("close mysong"), NULL, 0, NULL);//关闭报警音
				exit(0);
			}
			else if (checkGameLogic()) {
				cout << "\nYour blood is empty\nGame over, you lose" << endl;
				mciSendString(TEXT("open lose.wma alias mysong"), NULL, 0, NULL);
				mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//打开报警音
				Sleep(2000);
				mciSendString(TEXT("close mysong"), NULL, 0, NULL);//关闭报警音
				exit(0);
			}
		}
		else {
			chooseAction(room);
		}
	}
}




