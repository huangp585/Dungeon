#include<iostream>
#include<string>
#include<vector>
#include"Dungeon.h"
#include"Item.h"
#include"Monster.h"
#include"NPC.h"
#include"player.h"

using namespace std;

int main() {
	Dungeon dungeon = Dungeon();
	dungeon.runDungeon();
	return 0;
}