#pragma once
#include "Room.h"
#define TOTAL_ROOMS 2

class Dungeon {
public:
	Room rooms[TOTAL_ROOMS];
	int currentRoomIndex = 0;

	void loadRoom();
	bool hasMoreRooms();
	void goToNextRoom();
	Room *getCurrentRoom();
};