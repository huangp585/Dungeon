#include"Room.h"
#include"Monster.h"
#include"NPC.h"


Room::Room(): Object(){
	upRoom = NULL;
	downRoom = NULL;
	leftRoom = NULL;
	rightRoom = NULL;
	isExit = false;
	index = 0;
}

Room::Room(bool _isExit,int _index,vector<Object*> _objects):Object("Room"+to_string(_index), "Room"){
	upRoom = NULL;
	downRoom = NULL;
	leftRoom = NULL;
	rightRoom = NULL;
	isExit = _isExit;
	index = _index;
	objects = _objects;
}

void Room::setUpnDownRoom(Room* _uproom) {
	upRoom = _uproom;
	_uproom->downRoom = this;
}

void Room::setRightnLeftRoom(Room* _rightroom) {
	rightRoom = _rightroom;
	_rightroom->leftRoom = this;
}

Object* Room::popObject(Object* _object) {
	for (int i = 0; i < objects.size(); i++) {
		if (_object->getTag() == objects[i]->getTag()) {
			return objects[i];
		}
	}
}

void Room::deleteObject(Object* _object) {
	Monster* temp1= dynamic_cast<Monster*>(_object);
	NPC* temp2= dynamic_cast<NPC*>(_object);

	if (temp1 != NULL) {
		for (int i = 0; i < objects.size(); i++) {
			Monster* monster = dynamic_cast<Monster*>(objects[i]);
			if (monster != NULL) {
				objects.erase(objects.begin() + i);
			}
			else
				continue;
		}
	}
	if(temp2!=NULL) {
		for (int i = 0; i < objects.size(); i++) {
			NPC* npc = dynamic_cast<NPC*>(objects[i]);
			if (npc != NULL) {
				objects.erase(objects.begin() + i);
			}
			else
				continue;
		}
	}
}

                      //might send player,npc,monster
bool Room::triggerEvent(Object* _object) {
	Player* player = dynamic_cast<Player*>(_object);
	if (player != NULL) {
		objects.push_back(player);
	}
	NPC* npc = dynamic_cast<NPC*>(_object);
	if (npc != NULL) {
		objects.push_back(npc);
	}
	Monster* monster = dynamic_cast<Monster*>(_object);
	if (monster != NULL) {
		objects.push_back(monster);
	}
	return true;
}

void Room::setIsExit(bool a) {
	isExit = a;
}

void Room::setIndex(int a) {
	index = a;
}

void Room::setUpRoom(Room* a) {
	upRoom = a;
}
void Room::setDownRoom(Room* a) {
	downRoom = a;
}
void Room::setLeftRoom(Room* a) {
	leftRoom = a;
}
void Room::setRightRoom(Room* a) {
	rightRoom = a;
}


int Room::getIndex() {
	return index;
}

Room* Room::getUpRoom() {
	return upRoom;
}

Room* Room::getDownRoom() {
	return downRoom;
}

Room* Room::getLeftRoom() {
	return leftRoom;
}

Room* Room::getRightRoom() {
	return rightRoom;
}

bool Room::getIsExit() {
	return isExit;
}

vector<Object*> Room::getObjects() {
	return objects;
}

void Room::setObjects(vector<Object*> v) {
	objects = v;
}
