#include"Record.h"

void Record::savePlayer(Player* player, ofstream& outStream) {
	stringstream ss;

	//player
	/*ss.clear();
	ss.str("");
	ss << "Name maxHealth currentHealth attack defense currentRoomIndex PreviousRoomIndex InventoryNum\n";
	outStream << ss.str();*/

	ss.clear();
	ss.str("");
	ss << player->getName() << "/";
	outStream << ss.str();

	ss.clear();
	ss.str("");
	ss << player->getMaxHealth() << "/";
	outStream << ss.str();

	ss.clear();
	ss.str("");
	ss << player->getCurrentHealth() << "/";
	outStream << ss.str();

	ss.clear();
	ss.str("");
	ss << player->getAttack() << "/";
	outStream << ss.str();

	ss.clear();
	ss.str("");
	ss << player->getDefense() << "/";
	outStream << ss.str();

	ss.clear();
	ss.str("");
	ss << player->getCurrentRoom()->getIndex() << "/";
	outStream << ss.str();

	ss.clear();
	ss.str("");
	if (player->getPreviousRoom() == NULL) {
		ss << -1 << "/";
	}
	else {
		ss << player->getPreviousRoom()->getIndex() << "/";
	}
	outStream << ss.str();

	ss.clear();
	ss.str("");
	ss << player->getInventory().size() << "/";
	outStream << ss.str();

	//inventory
	vector<Item> v;
	v = player->getInventory();

	for (int i = 0; i < v.size(); i++) {
		/*ss.clear();
		ss.str("");
		ss << "Name Tag Health Attack Defense\n";
		outStream << ss.str();*/

		ss.clear();
		ss.str("");
		ss << v[i].getName() << "/";
		outStream << ss.str();

		ss.clear();
		ss.str("");
		ss << v[i].getTag() << "/";
		outStream << ss.str();

		ss.clear();
		ss.str("");
		ss << v[i].getHealth() << "/";
		outStream << ss.str();

		ss.clear();
		ss.str("");
		ss << v[i].getAttack() << "/";
		outStream << ss.str();

		ss.clear();
		ss.str("");
		ss << v[i].getDefense() << "/";
		outStream << ss.str();
	}
	outStream.close();
}

void Record::saveRooms(vector<Room*>& rooms, ofstream& outStream) {
	stringstream ss;

	//room
	/*ss.clear();
	ss.str("");
	ss << "isExit index num_objects\n";
	outStream << ss.str();*/

	for (int i = 0; i < rooms.size(); i++) {
		ss.clear();
		ss.str("");
		ss << rooms[i]->getIsExit() << "/";
		outStream << ss.str();

		ss.clear();
		ss.str("");
		ss << rooms[i]->getIndex() << "/";
		outStream << ss.str();

		ss.clear();
		ss.str("");
		ss << rooms[i]->getObjects().size() << "/";
		outStream << ss.str();


		//object
		vector<Object*> obj = rooms[i]->getObjects();
		for (int i = 0; i < obj.size(); i++) {
			GameCharacter* charactor = dynamic_cast<GameCharacter*>(obj[i]);
			/*ss.clear();
			ss.str("");
			ss << "Name tag maxHealth currentHealth attack defense" << "\n";
			outStream << ss.str();*/

			ss.clear();
			ss.str("");
			ss << charactor->getName() << "/";
			outStream << ss.str();

			ss.clear();
			ss.str("");
			ss << charactor->getTag() << "/";
			outStream << ss.str();

			if (charactor->getTag() == "Monster") {
				ss.clear();
				ss.str("");
				ss << charactor->getMaxHealth() << "/";
				outStream << ss.str();

				ss.clear();
				ss.str("");
				ss << charactor->getCurrentHealth() << "/";
				outStream << ss.str();

				ss.clear();
				ss.str("");
				ss << charactor->getAttack() << "/";
				outStream << ss.str();

				ss.clear();
				ss.str("");
				ss << charactor->getDefense() << "/";
				outStream << ss.str();
			}

			//npc or not
			NPC* npc = dynamic_cast<NPC*>(obj[i]);
			if (npc != NULL) {
				/*ss.clear();
				ss.str("");
				ss << "script" << "\n";
				outStream << ss.str();*/

				//npc script
				ss.clear();
				ss.str("");
				ss << npc->getScript();
				outStream << ss.str()<<"/";

				/*ss.clear();
				ss.str("");
				ss << "commodity" << "\n";
				outStream << ss.str();*/


				//npc commodity
				ss.clear();
				ss.str("");
				ss << npc->getCommodity().size()<<"/";
				outStream << ss.str();
				vector<Item> v;
				v = npc->getCommodity();

				for (int i = 0; i < v.size(); i++) {
					/*ss.clear();
					ss.str("");
					ss << "Name Tag Health Attack Defense\n";
					outStream << ss.str();*/

					ss.clear();
					ss.str("");
					ss << v[i].getName() << "/";
					outStream << ss.str();

					ss.clear();
					ss.str("");
					ss << v[i].getTag() << "/";
					outStream << ss.str();

					ss.clear();
					ss.str("");
					ss << v[i].getHealth() << "/";
					outStream << ss.str();

					ss.clear();
					ss.str("");
					ss << v[i].getAttack() << "/";
					outStream << ss.str();

					ss.clear();
					ss.str("");
					ss << v[i].getDefense() << "/";
					outStream << ss.str();
				}

			}
		}
	}
	outStream.close();
}

void Record::loadPlayer(Player* player, ifstream& inStream) {
	stringstream ss;

	ss.clear();
	ss.str("");

	string str;
	string Name;
	int a[7];

	getline(inStream, str, '/');
	ss << str;
	ss >> Name;
	//load player data
	for (int i = 0; i < 7; i++) {
		ss.clear();
		ss.str("");
		getline(inStream, str, '/');
		ss << str;
		ss >> a[i];
	}
	//player data

	/*int maxHealth;
	int currentHealth;
	int attack;
	int defense;
	int currentRoomIndex;
	int PreviousRoomIndex;
	int InventoryNum;*/

	player->setName(Name);
	player->setMaxHealth(a[0]);
	player->setCurrentHealth(a[1]);
	player->setAttack(a[2]);
	player->setDefense(a[3]);
	player->setIndex(a[4], a[5]);

	//load inventory
	vector<Item> v;
	for (int i = 0; i < a[6]; i++) {
		string Tag;
		int Health;
		int attack, defense;
		ss.clear();
		ss.str("");
		getline(inStream, str,'/');
		Name = str;

		ss.clear();
		ss.str("");
		getline(inStream, str, '/');
		ss << str;
		ss >> Tag;

		ss.clear();
		ss.str("");
		getline(inStream, str, '/');
		ss << str;
		ss >> Health;

		ss.clear();
		ss.str("");
		getline(inStream, str, '/');
		ss << str;
		ss >> attack;

		ss.clear();
		ss.str("");
		getline(inStream, str, '/');
		ss << str;
		ss >> defense;

		v.push_back(Item(Name, Health, attack, defense));
	}
	player->setInventory(v);
}

void Record::loadRooms(vector<Room*>& rooms, ifstream& inStream) {
	stringstream ss;
	string str;
	//load room
	int num_room = rooms.size();
	for (int i = 0; i < num_room; i++) {
		//room data
		bool isExit;
		int index;
		int num_objects;

		ss.clear();
		ss.str("");
		getline(inStream, str, '/');
		ss << str;
		ss >> isExit;

		ss.clear();
		ss.str("");
		getline(inStream, str, '/');
		ss << str;
		ss >> index;
		
		ss.clear();
		ss.str("");
		getline(inStream, str, '/');
		ss << str;
		ss >> num_objects;

		vector<Object*> temp;
		rooms[i]->setObjects(temp);
		rooms[i]->setIsExit(isExit);
		rooms[i]->setIndex(index);
		
		//load objects
		for (int j = 0; j < num_objects; j++) {
			string Name;
			string tag;
			int attack;
			int defense;

			ss.clear();
			ss.str("");
			getline(inStream, str, '/');
			Name = str;

			ss.clear();
			ss.str("");
			getline(inStream, str, '/');
			ss << str;
			ss >> tag;

			if (tag == "Monster") {
				int maxHealth;
				int currentHealth;

				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				ss << str;
				ss >> maxHealth;

				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				ss << str;
				ss >> currentHealth;

				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				ss << str;
				ss >> attack;

				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				ss << str;
				ss >> defense;

				Monster* monster=new Monster();
				monster->setName(Name);
				monster->setTag(tag);
				monster->setMaxHealth(maxHealth);
				monster->setCurrentHealth(currentHealth);
				monster->setAttack(attack);
				monster->setDefense(defense);

				rooms[i]->triggerEvent(monster);
			}
			else {
				NPC* npc=new NPC();
				npc->setName(Name);
				npc->setTag(tag);

				//load script
				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				npc->setScript(str);
				
				//load commodity
				int health;
				int num_commodity;

				vector<Item> commodity;
				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				ss << str;
				ss >> num_commodity;
				for (int k = 0; k < num_commodity; k++) {
				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				Name = str;

				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				tag = str;

				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				ss << str;
				ss >> health;

				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				ss << str;
				ss >> attack;

				ss.clear();
				ss.str("");
				getline(inStream, str, '/');
				ss << str;
				ss >> defense;

				commodity.push_back(Item(Name, health, attack, defense));
				}
				npc->setCommodity(commodity);
				rooms[i]->triggerEvent(npc);
			}
		}
	}
}


Record::Record() {
	;
}

void Record::saveToFile(Player* player, vector<Room*>& rooms) {
	ofstream p_outStream, r_outStream;
	p_outStream.open("save_player.txt");
	r_outStream.open("save_rooms.txt");
	savePlayer(player, p_outStream);
	saveRooms(rooms, r_outStream);
}

void Record::loadFromFile(Player* player, vector<Room*>& rooms) {
	ifstream p_inStream, r_inStream;
	p_inStream.open("save_player.txt");
	r_inStream.open("save_rooms.txt");
	loadRooms(rooms, r_inStream);
	loadPlayer(player, p_inStream);
	int c = player->getCurrentIndex();
	int p = player->getPreviousIndex();
	player->setCurrentRoom(rooms[c]);
	if (p == -1) {
		player->setPreviousRoom(NULL);
	}
	else {
		player->setPreviousRoom(rooms[p]);
	}
}


