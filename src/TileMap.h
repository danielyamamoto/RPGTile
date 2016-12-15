#pragma once

#include "Tile.h"
#include "Player.h"
#include "ofImage.h"

#define ROWS 24
#define COLS 32
#define TILES_IMG 8

class TileMap {

public:
	Tile map[ROWS][COLS];
	ofImage tImages[TILES_IMG];

	void loadMap(string name);
	void loadImages();
	vector<string> readFile(string fileName);
	void draw();
	Tile* testPlayerCollision(Player *player);
	Tile* testItemCollision(Player *player);
};