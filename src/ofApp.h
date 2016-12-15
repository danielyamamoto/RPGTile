#pragma once
#include "ofMain.h"
#include "Room.h"
#include "Player.h"
#include "Dungeon.h"

class ofApp : public ofBaseApp{

	public:
		Dungeon level;
		Room *actualRoom;
		Player player;
		float prevX, prevY;

		void setup();
		void update();
		void draw();
		void text();
		void gameOver();
		bool resetGame();
		void useItem(Tile *tile, int index);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
