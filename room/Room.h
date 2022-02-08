#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include"Object.h"

using namespace std;

class Monster;
class NPC;

class Room: public Object {
private:
	Room* upRoom;
	Room* downRoom;
	Room* leftRoom;
	Room* rightRoom;
	bool isExit;
	int index;
	
	vector<Object*> objects;
	/*contain 1 or multiple objects, 
	  including monster, npc, etc*/
public:
	Room();
	Room(bool, int, vector<Object*>);
	
	Object* popObject(Object*);
	/*pop out the specific object, 
	used when the interaction is done*/
	void deleteObject(Object*);//¥u°enpc and monster
	bool triggerEvent(Object*);//add object to the room

	/*set and get*/
	void setUpRoom(Room*);
	void setDownRoom(Room*);
	void setLeftRoom(Room*);
	void setRightRoom(Room*);

	void setUpnDownRoom(Room*);
	void setRightnLeftRoom(Room*);
	void setObjects(vector<Object*>);
	void setIsExit(bool);
	void setIndex(int);

	int getIndex();
	Room* getUpRoom();
	Room* getDownRoom();
	Room* getLeftRoom();
	Room* getRightRoom();
	bool getIsExit();
	vector<Object*> getObjects();
};


#endif
