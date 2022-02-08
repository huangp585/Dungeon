#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include"GameCharacter.h"
#include"Room.h"
#include"Item.h"

using namespace std;

class Item;//ta added;

class Player : public GameCharacter {
private:
	int current_index, previous_index;
	Room* currentRoom;
	Room* previousRoom;
	vector<Item> inventory;
public:
	Player();
	Player(string, int, int, int);
	void additem(Item);
	void increaseStatus(int,int,int);
	void changeRoom(Room*);

	/* Virtual function that you need to complete   */
	/* In Player, this function should show the     */
	/* status of player.                            */
	bool triggerEvent(Object*);
	/*set() get ()*/
	void setIndex(int, int);
	void setPreviousRoom(Room*);
	void setCurrentRoom(Room*);
	void setInventory(vector<Item>);

	int getCurrentIndex();
	int getPreviousIndex();
	Room* getPreviousRoom();
	Room* getCurrentRoom();
	vector<Item> getInventory();
};

#endif
