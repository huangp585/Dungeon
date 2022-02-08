#include"NPC.h"
#include"player.h"
#include"Dungeon.h"

using namespace std;

NPC::NPC(): GameCharacter(){
	;
}

NPC::NPC(string _name, string _script,            /*可在這增加角色*/
	vector<Item> _commodity) : GameCharacter(_name,"NPC",0, 0, 0){
	script = _script;
	commodity = _commodity;
}

void NPC::listCommodity() {
	for (int i = 0; i < commodity.size(); i++) {
		cout << i + 1 << ". " << commodity[i].getName() << endl;
	}
}

Item* NPC::sellitem(int index) {
	Item *bought = new Item();
	bought->setAttack(commodity[index].getAttack());
	bought->setDefense(commodity[index].getDefense());
	bought->setHealth(commodity[index].getHealth());
	bought->setName(commodity[index].getName());
	bought->setTag(commodity[index].getTag());

	commodity.erase(begin(commodity) + index);

	return bought;
}
                      //player
bool NPC::triggerEvent(Object* _object) {

	Player*_player = dynamic_cast<Player*>(_object);
	cout << "\n" << script << endl;
	cout << "which do you want ?" << endl;
	listCommodity();
	int choice;
	cin >> choice;
	Item* item = sellitem(choice - 1);
	item->triggerEvent(_player);
	_player->additem(*item);
	cout << "\n" << item->getName() << " is yours now!\n";
	return true;
}

void NPC::setScript(string s) {
	script = s;
}

string NPC::getScript() {
	return script;
}

vector<Item> NPC::getCommodity() {
	return commodity;
}

void NPC::setCommodity(vector<Item> v) {
	commodity = v;
}







