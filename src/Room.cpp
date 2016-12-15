#include "Room.h"

void Room::loadRoom(string name) {
	string bgName = "map"+name+".csv";
	string itemMap = "items"+name+".csv";
	map.loadMap(bgName);
	items.loadMap(itemMap);
	loadEnemies();
}

void Room::update(Player * player) {
	for (int i = 0; i < MAX_ENEMY; i++) {
		warriors[i].update(player);
	}
}

void Room::loadEnemies() {
	int currentEnemy = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (items.map[i][j].type == ENEMY) {
				warriors[currentEnemy].init(j * 32, i * 32, 28, 28);
				if (currentEnemy < MAX_ENEMY - 1) {
					currentEnemy++;
				}
			}
		}
	}
}

void Room::draw() {
	map.draw();
	items.draw();
	for (int i = 0; i < MAX_ENEMY; i++) {
		warriors[i].draw();
	}
}

void Room::eliminateWarrios(Player *player) {
	for (int i = 0; i < MAX_ENEMY; i++) {
		if (warriors[i].isAliveW) {
			float  dist = ofDist(player->position.x, player->position.y, warriors[i].position.x, warriors[i].position.y);
			if (dist < warriors[i].visionRange) {
				warriors[i].hp -= player->atk;
				if (warriors[i].hp <= 0) {
					warriors[i].isAliveW = false;
				}
			}
		}
	}
}