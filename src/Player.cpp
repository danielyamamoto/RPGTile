#include "Player.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

void Player::init(float x, float y, float w, float h) {
	cooldownTimer.setup(1000, false);
	invencible = false;
	ofAddListener(cooldownTimer.TIMER_REACHED, this, &Player::coolDownOver);
	hp = 50;
	atk = 2;
	vel = 5;
	level = 1;
	xp = 0;
	xpToLevelUp = 1;
	existingUpgrades = 0;
	damage = atk;
	isAlive = true;
	rect.set(x, y, w, h);
	position.set(x, y);
	size.set(w, h);
	velocity.set(vel, vel);
	col.set(0, 255, 255);
	inventory.init(20, ofGetHeight() - 42);
}

void Player::update() {
	if (moveUp) { position.y -= velocity.y; }
	else if (moveDown) { position.y += velocity.y; }
	if (moveLeft) { position.x -= velocity.x; } 
	else if (moveRight) { position.x += velocity.x; }
	rect.setPosition(position.x, position.y);
	levelUp();
}

void Player::draw() {
		ofSetColor(col);
		ofSetRectMode(OF_RECTMODE_CENTER);
	if (isAlive) {
		ofDrawRectangle(rect);
		inventory.draw();
		//onHit();
	} 
}

 void Player::setPosition(float x, float y) {
	position.set(x, y);
	rect.setPosition(x, y);
}

void Player::levelUp() {
	if (xp >= xpToLevelUp) {
		existingUpgrades++;
		level++;
		xp -= xpToLevelUp;
		xpToLevelUp = 2 + pow(2, level-1);
	}
}

void Player::levelHPUp() {
	hp = hp + 25;
	existingUpgrades--;
}

void Player::levelAtkUp() {
	atk++;
	existingUpgrades--;
}

void Player::levelVelUp() {
	vel += 0.5f;
	existingUpgrades--;
}

void Player::GetXP(int xp) {
	this->xp = xp;
}

void Player::damageRecive() {
	hp--;
}

void Player::coolDownOver(ofEventArgs & e) {
	invencible = false;
	col.set(col);
}

void Player::onHit() {
	if (!invencible) {
		invencible = true;
		cooldownTimer.reset();
		cooldownTimer.startTimer();
		col.set(255);
		hp--;
	}
}