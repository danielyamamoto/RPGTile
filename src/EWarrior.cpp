#include "EWarrior.h"

void EWarrior::init(float x, float y, float w, float h)
{
	rect.set(x, y, w, h);
	position.set(x, y);
	size.set(w, h);
	initPoint.set(x, y);
	endPoint.set(x + 200.0f, y);
	velocity.set(3.0f, 3.0f);
	col.set(0, 255, 0);
	state = PATROL;
	visionRange = 100;
	attackRange = 30;
	hp = 15;
	isAliveW = true;
}

void EWarrior::update(Player * player)
{
	if (isAliveW) {
		rect.setPosition(position.x, position.y);
		switch (state) {
		case PATROL:
			patrol(player);
			break;
		case SEEK:
			seek(player);
			break;
		case ATTACK:
			attack(player);
			break;
		}
	}
}

void EWarrior::patrol(Player *player)
{
	//Distancia del jugador al enemigo
	float dist = ofDist(player->position.x, player->position.y, position.x, position.y);

	//Si el jugador está dentro del rango de visión
	if (dist < visionRange) {
		state = SEEK;
	}
	else {
		if (position.x > endPoint.x) {
			velocity.x *= -1;
		}
		else if (position.x < initPoint.x) {
			velocity.x *= -1;
		}
		position.x += velocity.x;
	}
}

void EWarrior::seek(Player *player) {
	//Calcula la distancia entre el jugador y el enemigo
	float dist = ofDist(player->position.x, player->position.y, position.x, position.y);
	//Si el jugador está fuera del rango de visión
	if (dist > visionRange) {
		//Regresa al estado de Patrullar
		ofVec2f returnVelocity = initPoint - position;
		returnVelocity.normalize();
		returnVelocity *= 3.2;
		position.x += returnVelocity.x;
		position.y += returnVelocity.y;;

		float arriveDist = ofDist(initPoint.x, initPoint.y, position.x, position.y);
		if (arriveDist < 2) {
			position.x = initPoint.x;
			position.y = initPoint.y;
			state = PATROL;
		}
	}
	else if (dist < attackRange) {	
		//Atacar
		state = ATTACK;
	}
	else {
		ofVec2f seekVelocity = player-> position - position;
		seekVelocity.normalize();
		seekVelocity *= 3.0f;
		position.x += seekVelocity.x;
		position.y += seekVelocity.y;
		//Continua con patrullaje
	}
}

void EWarrior::attack(Player *player) {
	float dist = ofDist(player->position.x, player->position.y, position.x, position.y);
	float arriveDist = ofDist(initPoint.x, initPoint.y, position.x, position.y);
	if (dist < visionRange) { //SI EL JUGADOR ENTRA EN EL RANGO DE VISION DEL ENEMIGO 
		state = SEEK; //EL ENEMIIGO CAMBIA AL ESTADO DE SEGUIR AL JUGADOR
	}
	if (arriveDist < 2) {
		position.x = initPoint.x;
		position.y = initPoint.y;
		state = PATROL;
	}
	if (player->hp > 0) { 
		player->damageRecive(); 
	}
	if (player->hp <= 0) {
		player->isAlive = false;
		if (player->isAlive = false) player->hp = 0;
	}
}

void EWarrior::reciveDamage(int damage) {
	hp -= damage;
}

void EWarrior::draw() {
	if (isAliveW) {
		ofSetColor(col);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(rect);
	}
}

bool EWarrior::isAlive(Player * player) {
	if (hp > 0) {
		//isAliveW = true;
		return true;
	}
	else if (hp <= 0) {
		//player->GetXP(5);
		player->xp++;
		eliminate();
		return true;
	}
	return false;
}

void EWarrior::eliminate() {
	hp = -1;
}