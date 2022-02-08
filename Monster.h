#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include"GameCharacter.h"
#include<Windows.h>
#include<mmsystem.h>
#include<dsound.h>
#pragma comment(lib,"WINMM.LIB")

 
class Player;

using namespace std;

class Monster: public GameCharacter{
public:
	Monster();
	Monster(string, int, int,int);
	/* Virtual function that you need to complete   */
	/* In Monster, this function should deal with   */
	/* the combat system.                           */
	bool triggerEvent(Object*);
};

#endif
