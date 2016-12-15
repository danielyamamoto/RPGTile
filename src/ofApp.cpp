#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	level.loadRoom();
	actualRoom = level.getCurrentRoom();
	player.init(80, 55, 28, 28);
	ofSetFrameRate(60);
	actualRoom->loadEnemies();
}

//--------------------------------------------------------------
void ofApp::update(){
	player.update(); //Habilita movimiento en el personaje
	actualRoom->update(&player);
	
	Tile *tile = actualRoom->map.testPlayerCollision(&player);
	if (tile != NULL) {
		if (tile->type == WALL) {
			player.update();
			player.setPosition(prevX, prevY);
		}
		else {
			level.goToNextRoom();
			actualRoom = level.getCurrentRoom();
			player.update();
			player.init(16, 710, 28, 28);
		}
	}
	
	Tile* item = actualRoom->items.testItemCollision(&player); //Guarda Item
	if (item != NULL) { //Sabe cuando hay o no hay disponibilidad para agarrar más items
		if (player.inventory.storeItem(item)) {
			item->active = false;
		}
		else {
			cout << "Inventario lleno" << endl;
		}
	}
	prevX = player.rect.x;
	prevY = player.rect.y;
}

//--------------------------------------------------------------
void ofApp::draw(){
	actualRoom->draw();
	player.draw();
	text();
	gameOver();
}

void ofApp::text() {
	ofSetColor(255);
	string Health = "Vida: " + ofToString(player.hp);
	string Damage = "Ataque: " + ofToString(player.atk);
	string Velocity = "Velocidad: " + ofToString(player.velocity);
	string Level = "Nivel: " + ofToString(player.level);
	string XP = "XP: " + ofToString(player.xp);
	string Upgrades = "Mejoras: " + ofToString(player.existingUpgrades);
	string XPNeeded = "XP-Necesaria: " + ofToString(player.xpToLevelUp);
	ofDrawBitmapString(Health, 20, 20);
	ofDrawBitmapString(Damage, 120, 20);
	ofDrawBitmapString(Velocity, 220, 20);
	ofDrawBitmapString(XP, 370, 20);
	ofDrawBitmapString(Level, 470, 20);
	ofDrawBitmapString(Upgrades, 570, 20);
	ofDrawBitmapString(XPNeeded, 670, 20);
}

void ofApp::gameOver() {
	if (player.hp <= 0) {
		string gameOver = "         GAME OVER\n\nPRESIONE R PARA CONTINUAR ";
		ofDrawBitmapString(gameOver, ofGetWidth() / 2 - 25, ofGetHeight() / 2 - 25);
	}
}

bool ofApp::resetGame() {
	if (player.hp <= 0) {
		setup();
	}
	return false;
}

void ofApp::useItem(Tile * tile, int index) {
	if (tile->type == HP) {
		player.hp += 25;
		player.inventory.resetSlot(index);
	}
	else if (tile->type == ATK) {
		player.atk += 1;
		player.inventory.resetSlot(index);
	}
	else if (tile->type == VEL) {
		player.xp = player.xp + 5;
		player.inventory.resetSlot(index);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'w' || key == 'W' || key == OF_KEY_UP) { player.moveUp = true; }
	else if (key == 's' || key == 'S' || key == OF_KEY_DOWN) { player.moveDown = true; }
	if (key == 'a' || key == 'A' || key == OF_KEY_LEFT) { player.moveLeft = true; }
	else if (key == 'd' || key == 'D' || key == OF_KEY_RIGHT) { player.moveRight = true; }
	if (key == 'r' || key == 'R') { resetGame(); }
	if (key == ' ') { actualRoom->eliminateWarrios(&player); }
	
	if (player.existingUpgrades > 0) {
		if (key == '5') { player.levelAtkUp(); }
		else if (key == '4') { player.levelHPUp(); }
		else if (key == '6') { player.levelVelUp(); }
	}

	if (key == '1') { 
		Tile *item = player.inventory.getItem(0);
		if (item != NULL) {
			useItem(item, 0);
		}
	}
	else if(key == '2') { 
		Tile *item = player.inventory.getItem(1); 
		if (item != NULL) {
			useItem(item, 1);
		}
	}
	else if (key == '3') { 
		Tile *item = player.inventory.getItem(2);
		if (item != NULL) {
			useItem(item, 2);
		}
	}
	else if (key == '4') { 
		Tile *item = player.inventory.getItem(3); 
		if (item != NULL) {
			useItem(item, 3);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'w' || key == 'W' || key == OF_KEY_UP) { player.moveUp = false; }
	else if (key == 's' || key == 'S' || key == OF_KEY_DOWN) { player.moveDown = false; }
	if (key == 'a' || key == 'A' || key == OF_KEY_LEFT) { player.moveLeft = false; }
	else if (key == 'd' || key == 'D' || key == OF_KEY_RIGHT) { player.moveRight = false; }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
