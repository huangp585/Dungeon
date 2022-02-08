#include"Item.h"

Item::Item():Object() {
	health = 0;
	attack = 0;
	defense = 0;
}

Item::Item(string _name, int _health, int _attack, int _defense)
	: Object(_name, "item"){
	health = _health;
	attack = _attack;
	defense = _defense;
}

bool Item::triggerEvent(Object* _object) {
	Player* _player = dynamic_cast<Player*>(_object);
	_player->increaseStatus(health, attack, defense);
	if (_player != NULL) {
		return true;
	}
	else
		return false;
}


void Item::setHealth(int _health) {
	health = _health;
}
void Item::setAttack(int _attack) {
	attack = _attack;
}
void Item::setDefense(int _defense) {
	defense = _defense;
}
int Item::getHealth() {
	return health;
}
int Item::getAttack() {
	return attack;
}
int Item::getDefense() {
	return defense;
}
