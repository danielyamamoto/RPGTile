#pragma once
#include "ofRectangle.h"
#include "ofImage.h"
#include "ofColor.h"

enum { WALL, FLOOR, HP, RESPAWN, VEL, ATK, DOOR, ENEMY, SLOT};

class Tile {
public:
	ofRectangle rect;
	ofImage *image;
	ofColor col;
	int type;
	bool active;

	void init(float x, float y, float size, int type, ofImage *img);
	void draw();
};