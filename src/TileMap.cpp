#include "TileMap.h"
#include "ofUtils.h"

void TileMap::loadMap(string name) {
	int x = 0;
	int y = 0;
	vector<string> m = readFile(name);
	loadImages();

	for (int i = 0; i < ROWS; i++) {
		string row = m[i];
		vector<string> cols = ofSplitString(row, ",");
		for (int j = 0; j < cols.size(); j++) {
			int type = ofToInt(cols[j]);
			if (type >= 0 && type <= 7) {
				map[i][j].init(x + j * 32, y + i * 32, 32, type, &tImages[type]); //Carga mapa mediante los tiles
			}
			else {
				map[i][j].init(x + j * 32, y + i * 32, 32, type, NULL);
			}
		}
	}
}

void TileMap::loadImages() {
	tImages[WALL].load("muro.jpg"); //0
	tImages[FLOOR].load("suelo.jpg"); //1
	tImages[HP].load("hp.jpg"); //2
	tImages[RESPAWN].load("respawn.jpg"); //3
	tImages[VEL].load("vel.jpg"); //4
	tImages[ATK].load("atk.jpg"); //5
	tImages[DOOR].load("door.jpg"); //6
	tImages[ENEMY].load("enemy.jpg"); //7
}

vector<string> TileMap::readFile(string fileName) {
	string path = "data/" + fileName;
	ifstream file(path);
	string data;
	vector<string> lines;

	if (file.is_open()) {
		while (getline(file, data)) {
			cout << data << endl;
			lines.push_back(data);
		}
	} else {
		cout << "Error opening file: " << path << endl;
	}
	return lines;
}


void TileMap::draw() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			map[i][j].draw();
		}
	}
}

Tile* TileMap::testPlayerCollision(Player *player)
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			Tile *tile = &map[i][j];
			if (tile->type == WALL || tile->type == DOOR) {
				if (tile->rect.intersects(player->rect)) {
					return tile;
				}
			}
		}
	}
	return NULL;
}

Tile* TileMap::testItemCollision(Player * player) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			Tile *tile = &map[i][j];
			int type = tile->type;
			if(tile->active){
				if (type == HP || type == ATK || type == VEL) {  //Colision con items
					if (tile->rect.intersects(player->rect)) {
						return tile;
					}
				}
			}
		}
	}
	return NULL;
}