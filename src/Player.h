#pragma once
#include "ofRectangle.h"
#include "Inventario.h"
#include "ofColor.h"
#include "ofVec2f.h"
#include "ofxTimer.h"

class Player {

public:
	int hp, atk, xp, vel, level, xpToLevelUp, existingUpgrades, damage;
	bool moveUp, moveDown, moveLeft, moveRight;
	bool isAlive;

	ofRectangle rect;
	ofColor col;
	ofVec2f velocity, position, size;
	Inventory inventory;

	bool invencible;
	ofxTimer cooldownTimer;
	
	void init(float x, float y, float w, float h);
	void update();
	void draw();
	void setPosition(float x, float y);
	void levelUp();
	void levelHPUp();
	void levelAtkUp();
	void levelVelUp();
	void GetXP(int XP);
	void damageRecive();
	void onHit();
	void coolDownOver(ofEventArgs &e);
};