#pragma once
#include "Tile.h"
#include "ofImage.h"
#define SLOTS 4

class Inventory {
public:
	float x, y;
	float offset;
	Tile tilesSlots[SLOTS];
	ofImage img;

	void init(float x, float y);
	Tile* getItem(int index);
	void resetSlot(int index);
	bool storeItem(Tile *tile);
	void draw();
};