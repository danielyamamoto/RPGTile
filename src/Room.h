#pragma once
#include "TileMap.h"
#include "EWarrior.h"
#include "Player.h"
#define MAX_ENEMY 13

class Room {
public:
	TileMap map;
	TileMap items;
	EWarrior warriors[MAX_ENEMY];

	void loadRoom(string name);
	void update(Player *player);
	void loadEnemies();
	void draw();
	void eliminateWarrios(Player *player);
};