#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include"Item.h"
#include"GameCharacter.h"

class Player;

using namespace std;

class NPC :public GameCharacter {
private:
	string script;
	vector<Item> commodity;
	Item* sellitem(int);//used in triggerEvent

	/*print all the Item in this NPC*/
public:
	NPC();
	NPC(string, string, vector<Item>);

	/* Virtual function that you need to complete   */
	/* In NPC, this function should deal with the   */
	/* transaction in easy implementation           */
	bool triggerEvent(Object*);

	void listCommodity();//used in triggerEvent
	/*set and get*/
	string getScript();
	vector<Item> getCommodity();
	void setCommodity(vector<Item>);
	void setScript(string s);
};

#endif
