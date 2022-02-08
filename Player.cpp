#include<iostream>
#include<string>
#include<vector>
#include"GameCharacter.h"
#include"Room.h"
#include"Item.h"
#include"Object.h"
#include"player.h"

using namespace std;

Player::Player(): GameCharacter(){
	currentRoom = NULL;
	previousRoom = NULL;
	current_index = -1;
	previous_index = -1;
}

Player::Player(string _name, int _health, int _attack
	, int _defense) : GameCharacter(_name, "player", _health, _attack, _defense){
	current_index = -1;
	previous_index = -1;
	currentRoom = NULL;
	previousRoom = NULL;
}

void Player::additem(Item item) {
	inventory.push_back(item);
}

void Player::increaseStatus(int _health,int _attack,int _defense) {
	int currentHealth = this->getCurrentHealth();
	int attack = this->getAttack();
	int defense = this->getDefense();

	currentHealth += _health;
	attack += _attack;
	defense += _defense;

	setCurrentHealth(currentHealth);
	setAttack(attack);
	setDefense(defense);
	if (currentHealth > getMaxHealth()) {
		setMaxHealth(currentHealth);
	}
}

void Player::changeRoom(Room *target) {
	previousRoom = currentRoom;
	currentRoom = target;
}

bool Player::triggerEvent(Object* _object) {
	Player* _player = dynamic_cast<Player*>(_object);
	if (_player == NULL) {
		return false;
	}
	
	else if (_player != NULL) {
		cout << "\nStatus : " << endl;
		cout << "[" << _player->getName() << "]" << endl;
		cout << "> Health : " << _player->getCurrentHealth() << "/" << _player->getMaxHealth() << endl;
		cout << "> Attack : " << _player->getAttack() << endl;
		cout << "> Defense : " << _player->getDefense() << endl;
		return true;
	}
	else {
		return false;
	}
}

void Player::setPreviousRoom(Room* _room) {
	previousRoom = _room;
}

void Player::setCurrentRoom(Room* _room) {
	currentRoom = _room;
}

void Player::setInventory(vector<Item> v) {
	inventory = v;
}


vector<Item> Player::getInventory() {
	return inventory;
}


Room* Player::getPreviousRoom() {
	return previousRoom;
}

Room* Player::getCurrentRoom() {
	return currentRoom;
}

void Player::setIndex(int c,int p) {
	current_index = c;
	previous_index = p;
}

int Player::getCurrentIndex() {
	return current_index;
}

int Player::getPreviousIndex() {
	return previous_index;
}
