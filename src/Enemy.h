#pragma once
#include "ofRectangle.h"
#include "ofColor.h"
#include "ofVec2f.h"

class Enemy {
public:
	ofVec2f position, size;
	ofRectangle rect;
	ofColor col;

	void init(float x, float y, float w, float h);
	void update();
	void draw();
};