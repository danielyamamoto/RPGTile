#include "Inventario.h"

void Inventory::init(float x, float y) {
	img.load("slot.jpg");
	offset = 20;
	for (int i = 0; i < SLOTS; i++) {
		tilesSlots[i].init(x + (i*32) + (i*offset), y, 32, SLOT, &img);
	}
}

Tile* Inventory::getItem(int index) {
	if (index >= 0 && index < SLOTS) {
		//return &tilesSlots[index];
		if (tilesSlots[index].type != SLOT) { //Valida que sea un item valido
			return &tilesSlots[index];
		}
	}
	return NULL;
}

void Inventory::resetSlot(int index) {
	if (index >= 0 && index < SLOTS) {
		tilesSlots[index].type = SLOT;
		tilesSlots[index].image = &img;
	}
}

bool Inventory::storeItem(Tile *tile) {
	for (int i = 0; i < SLOTS; i++) {
		if (tilesSlots[i].type == SLOT) {
			tilesSlots[i].type = tile->type;
			tilesSlots[i].image = tile->image;
			return true;
		}
	}
	return false;
}

void Inventory::draw() {
	for (int i = 0; i < SLOTS; i++) {
		tilesSlots[i].draw();
	}
}