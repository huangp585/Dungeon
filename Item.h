#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include"Object.h"
#include"player.h"//ta added

using namespace std;

class Player;//Ta added

class Item :public Object {
public:
	Item();
	Item(string _name, int _health, int _attack, int _defense);
	
/* Virtual function that you need to complete    */
/* In Item, this function should deal with the   */
/* pick up action. You should add status to the  */
/* player.                                       */
	bool triggerEvent(Object*);

	/*set and get function*/
	void setHealth(int _health);
	void setAttack(int _attack);
	void setDefense(int _defense);
	int getHealth();
	int getAttack();
	int getDefense();
private:
	int health, attack, defense;
};

#endif
