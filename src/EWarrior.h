#pragma once
#include "Enemy.h"
#include "Player.h"

enum {PATROL, SEEK, ATTACK};

class EWarrior : public Enemy {
public:
	ofVec2f initPoint, endPoint, velocity;
	float rangeRadius, visionRange, attackRange;
	ofRectangle weapon;
	int state, hp;
	bool isAliveW;

	void init(float x, float y, float w, float h);
	void update(Player *player);
	void patrol(Player *player);
	void seek(Player *player);
	void reciveDamage(int damage);
	void draw();
	bool isAlive(Player *player);
	void attack(Player *player);
	void eliminate();
};