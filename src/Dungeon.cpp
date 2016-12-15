#include "Dungeon.h"

void Dungeon::loadRoom() {
	currentRoomIndex = 0;
	rooms[0].loadRoom("level1");
	rooms[1].loadRoom("level2");
}

bool Dungeon::hasMoreRooms() {
	if (currentRoomIndex < TOTAL_ROOMS-1) {
		return true;
	}
	return false;
}

void Dungeon::goToNextRoom() {
	if (hasMoreRooms()) {
		currentRoomIndex++;
	}
}

Room * Dungeon::getCurrentRoom() {
	return &rooms[currentRoomIndex];
}