#include "Enemy.h"
#include "ofGraphics.h"


void Enemy::init(float x, float y, float w, float h) {
	rect.set(x, y, w, h);
	position.set(x, y);
	size.set(w, h);
	col.set(0, 255, 0);
}

void Enemy::update() {
	rect.setPosition(position.x, position.y);
}

void Enemy::draw() {
	ofSetColor(col);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawRectangle(rect);
}