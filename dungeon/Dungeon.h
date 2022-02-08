#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include<Windows.h>
#include<mmsystem.h>
#include<dsound.h>
#pragma comment(lib,"WINMM.LIB")

#include<iostream>
#include<string>
#include<vector>
#include <exception>//ta added
#include "player.h"
#include "Monster.h"
#include "NPC.h"
#include "Room.h"
#include "Record.h"


using namespace std;

class Dungeon :public Player, public Room {
private:
	Player player;
	vector<Room*> rooms;
public:
	Dungeon();

	/* Create a new player, and give him/her basic status */
	void createPlayer();

	/* Create a map, which include several different rooms */
	void createMap();

	/* Deal with player's moveing action */
	void handleMovement();

	/* Deal with player's iteraction with objects in that room */
	bool handleEvent(Object*);

	/* Deal with all game initial setting       */
	/* Including create player, create map etc  */
	void startGame();

	/* Deal with the player's action     */
	/* including showing the action list */
	/* that player can do at that room   */
	/* and dealing with player's input   */
	void chooseAction(Room*);

	/* Check whether the game should end or not */
	/* Including player victory, or he/she dead */
	bool checkGameLogic();

	/* Deal with the whole game process */
	void runDungeon();
};


#endif