#include "Tile.h"
#include "ofGraphics.h"

void Tile::init(float x, float y, float size, int type, ofImage *img)
{
	rect.set(x + 16, y + 16, size, size);
	this->type = type;
	image = img;
	col.set(255);
	active = true;
}

void Tile::draw() {
	if (active) {
		if (image != NULL) {
			ofSetColor(col);
			image->draw(rect.x, rect.y);
		}
	}
}
