#include"Monster.h"
#include"player.h"
using namespace std;

Monster::Monster():GameCharacter(){
	;
}

Monster::Monster(string _name, int _health, int _attack, 
	             int _defense): GameCharacter(_name, "Monster", _health, _attack, _defense){
	;
}

                                   //player
bool Monster::triggerEvent(Object* _object) {
	cout << "\nA Monster is in front of you!!\nchoose your action! :" << endl;
	cout << "a : attack!\nb : retreat!" << endl;
	char choice;
	cin >> choice;

	Player* _player = dynamic_cast<Player*>(_object);
	int monsterBlood = getCurrentHealth();
	int monster_maxBlood = getMaxHealth();
	int monsterAttack = getAttack();
	int playerBlood = _player->getCurrentHealth();
	int player_maxBlood = _player->getMaxHealth();
	int playerAttack = _player->getAttack();

	//attack
	while (playerBlood != 0 || monsterBlood != 0) {
		if (choice == 'a') {
			//player first hit the monster
			mciSendString(TEXT("open attack.wma alias mysong"), NULL, 0, NULL);
			mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//打开报警音
			Sleep(1000);
			mciSendString(TEXT("close mysong"), NULL, 0, NULL);//关闭报警音
			monsterBlood = this->takeDamage(playerAttack);
			//check if the monster dead
			if (monsterBlood <= 0) {
				//cout << "Congratulation! You win!!" << endl;
				return true;
			}
			cout << "\nYou hit the Monster!" << endl;
			cout << "the blood of Monster : " << monsterBlood << "/" << monster_maxBlood << endl;


			//monster hit the player
			playerBlood = _player->takeDamage(monsterAttack);
			//check if the player dead
			if (playerBlood <= 0) {
				//cout << "You are dead, Game Over" << endl;
				return false;
			}
			cout << "\nthe Monster attacks you!" << endl;
			cout << "your blood : " << playerBlood << "/" << player_maxBlood << endl;

			cout << "\nThe Monster is still alive!!\nchoose your action! :" << endl;
			cout << "a : attack!\nb : retreat!" << endl;
			cin >> choice;
			//combat結束
			//若是最後的房間，則勝利
			//若不是，則進到下一個房間
		}
		else if (choice == 'b') {
			//go back to the previous room
			Room* previousRoom = _player->getPreviousRoom();
			Room* currentRoom = _player->getCurrentRoom();
			Room* tmp = previousRoom;
			_player->setPreviousRoom(currentRoom);
			_player->setCurrentRoom(tmp);
			cout << "\nyou are back to Room" << _player->getCurrentRoom()->getIndex() << endl;
			return false;
		}
	}
}
