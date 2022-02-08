#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include<iostream>
#include<string>
#include"Object.h"

using namespace std;

class GameCharacter: public Object{
public:
	GameCharacter();
	GameCharacter(string _name, string _tag, 
		          int _health, int _attack, int _defense);
	/*可在tag部分增加職業*/
	int takeDamage(int enemyAttack);
	bool checkIsDead();

	/*set anad get function*/
	int getMaxHealth();
	int getCurrentHealth();
	int getAttack();
	int getDefense();
	void setMaxHealth(int);
	void setCurrentHealth(int);
	void setAttack(int);
	void setDefense(int);
private:
	//string name;
	int maxHealth;
	int currentHealth;
	int attack;
	int defense;
};

#endif // !GAMECHARACTER_H_INCLUDED

