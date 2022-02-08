#include"GameCharacter.h"

GameCharacter::GameCharacter(): Object(){
	maxHealth = 0;
	currentHealth = 0;
	attack = 0;
	defense = 0;
}

GameCharacter::GameCharacter(string _name, string _tag, 
	int _health, int _attack, int _defense): Object(_name, _tag){
	maxHealth = _health;
	currentHealth = _health;
	attack = _attack;
	defense = _defense;
}

bool GameCharacter::checkIsDead() {
	if (currentHealth == 0) {
		return true;
	}
	else
		return false;
}

int GameCharacter::takeDamage(int enemyAttack) {
	if (defense > 0 && defense<enemyAttack) {
		currentHealth -= enemyAttack - defense;
		defense -= 10;
		if (defense < 0) {
			defense = 0;
		}
	}
	else if (defense > enemyAttack) {
		defense -= 5;
		if (defense < 0) {
			defense = 0;
		}
		currentHealth -= 5;
	}
	else {
		currentHealth -= enemyAttack;
	}

	return currentHealth;
}

int GameCharacter::getMaxHealth() {
	return maxHealth;
}

int GameCharacter::getCurrentHealth() {
	return currentHealth;
}
int GameCharacter::getAttack() {
	return attack;
}
int GameCharacter::getDefense() {
	return defense;
}

void GameCharacter::setMaxHealth(int a) {
	maxHealth = a;
}
void GameCharacter::setCurrentHealth(int a) {
	currentHealth = a;
}
void GameCharacter::setAttack(int a) {
	attack = a;
}
void GameCharacter::setDefense(int a) {
	defense = a;
}
