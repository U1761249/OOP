
#include <time.h>
#include <cmath>
#include "DungeonGenerator.h"
#include "Dungeon.h"
using namespace std;

/**
 * Used to begin the generation of the dungeon.
 * Begin by generating the treasure room.
 * Use another function to recursively define the other rooms.
 * Finally set the spawn room.
 */
void DungeonGenerator::startGenerating() {
    int dungeonMemoryLoc = reinterpret_cast<int>(&dungeonMemoryLoc);    // Integer = integer's location as an integer.
    int dungeonMemoryLoc2 = reinterpret_cast<int>(&dungeonMemoryLoc2);
    srand(time(nullptr) * dungeonMemoryLoc % dungeonMemoryLoc2); // use current time and 2 random ints as seed for random generaton

    Dungeon *dungeon = Dungeon::getInstance();

    int treasureX = rand() % sizeX;
    int treasureY = rand() % sizeY;

    dungeon->setRoom(treasureX, treasureY, 1); // Set room at co-ordinates to treasure room.#
    roomCount ++;

    int direction;
    do {
        direction = rand() % 4;
    } while (!checkDoors( (treasureY * sizeX) + treasureX , direction));
    dungeon->setDoor((treasureY * sizeX) + treasureX, direction, true);
    int destination = nextIndex(treasureX, treasureY, direction);
    newRoom(destination, direction);

    setSpawn(treasureX, treasureY);
}

/**
 * Generate a new room.
 * @param index of the new room
 * @param origin of the room that called this method (Where it was created from).
 */
void DungeonGenerator::newRoom(int index, int origin) {
    Dungeon *dungeon = Dungeon::getInstance();
    int x = index % sizeX;
    int y = (index - x) / sizeX;
    if (!dungeon->getRoom(index).isCreated() && index < dungeon->getSize()) {
        dungeon->setRoom(x, y, 0);  // Create the room
        roomCount ++;
        generateDoors(x, y, origin);
        for (int i = 0; i < 4; i++){
            if(dungeon->getRoom(x, y).getDoor(i)){
                int destination = nextIndex(x, y, i);
                newRoom(destination, i);
            }
        }
    }

}

/**
 * Generate doors for the new Room. Uses a Random number to generate a door and calls CheckDoors to check it.
 * @param x of the current room.
 * @param y of the current room.
 * @param origin of the current room (Where it was created from).
 */
void DungeonGenerator::generateDoors(int x, int y, int origin) {
    Dungeon *dungeon = Dungeon::getInstance();
    int dungeonMemoryLoc = reinterpret_cast<int>(&dungeonMemoryLoc);    // Integer = integer's location as an integer.
    int dungeonMemoryLoc2 = reinterpret_cast<int>(&dungeonMemoryLoc2);
    srand(time(nullptr) * dungeonMemoryLoc %
          dungeonMemoryLoc2); // use current time and 2 random ints as seed for random generator

    int index = (y * sizeX) + x;
    bool doors[4];
    int doorCount = 0;
    for (int i = 0; i < 4; i++) {
        doors[i] = rand() % 2;
        if (doors[i]) {
            doors[i] = checkDoors(index, i);
            doorCount++;
        }
        dungeon->setDoor(index, i, doors[i]);
    }
    if (!dungeon->getRoom(x, y).getDoor((origin + 2) % 4)) {
        doorCount++;
        dungeon->setDoor(index, (origin + 2) % 4, true);
    }

    if (doorCount == 1) {    // If room has no doors, try again (not endlessly)
        for (int i = 0; i < 4; i++) {
            doors[i] = rand() % 2;
            if (doors[i]) {
                doors[i] = checkDoors(index, i);
            }
            dungeon->setDoor(index, i, doors[i]);
        }
        if (!dungeon->getRoom(x, y).getDoor((origin + 2) % 4)) {
            dungeon->setDoor(index, (origin + 2) % 4, true);
        }

    }
}

/**
 * Check that the generated doors are possible.
 * @param index of the current room.
 * @param direction that is being checked.
 */
bool DungeonGenerator::checkDoors(int index, int direction) {
    // door already known to be true.
    Dungeon *dungeon = Dungeon::getInstance();
    int x = index % sizeX;
    int y = (index - x) / sizeX;
    bool valid = true;

    bool toReturn;
    int destination = 0;
    switch (direction){
        case 0 : //North
            y = y - 1;  // Go up 1 row.
            break;
        case 1 : //East
            if ((index + 1) % sizeX == 0) valid = false; // cannot jump rows
            else x = x + 1;        // Go right 1 room.
            break;
        case 2 : //South
            y = y + 1;  // Go down 1 row.
            break;
        case 3 : //West
            if (index % sizeX == 0) valid = false; // cannot jump rows
            else x = x - 1;       // Go left 1 room.
            break;
    }

    destination = (y * sizeX) + x;

    try {
        if (!valid || y > sizeY || x > sizeX) {toReturn = false;}

        else if (destination >= dungeon->getSize()){toReturn = false;}

        else if (dungeon->getRoom(destination).getType() == 1){ // Cannot add doors to treasure room1
            toReturn = false;
        }

        else if (dungeon->getRoom(destination).isCreated()){   // If room at destination already exists
            if (rand() % 2){  // 50% add door to both rooms, 50% scrap door.
                dungeon->setDoor(destination, (direction + 2) % 4, toReturn = true);
            }
            else toReturn = false;
        }
        else toReturn = true;
    }
    catch (const std::out_of_range& oor) {}
    return toReturn;
}

/**
 * Get the next index based on the direction being generated to.
 * @param x of the current room.
 * @param y of the current room.
 * @param direction to the next room from the current room.
 * @return index of the next room.
 */
int DungeonGenerator::nextIndex(int x, int y, int direction) {

    switch (direction){
        case 0 : //North
            y = y - 1;  // Go up 1 row.
            break;
        case 1 : //East
            x = x + 1;        // Go right 1 room.
            break;
        case 2 : //South
            y = y + 1;  // Go down 1 row.
            break;
        case 3 : //West
            x = x - 1;       // Go left 1 room.
            break;
    }

    return (y * sizeX) + x;
}

/**
 * Set the spawn of the dungeon.
 * @param treasureX
 * @param treasureY
 */
void DungeonGenerator::setSpawn(int treasureX, int treasureY) {
    Dungeon *dungeon = Dungeon::getInstance();
    int dungeonMemoryLoc = reinterpret_cast<int>(&dungeonMemoryLoc);    // Integer = integer's location as an integer.
    int dungeonMemoryLoc2 = reinterpret_cast<int>(&dungeonMemoryLoc2);
    srand(time(nullptr) * dungeonMemoryLoc % dungeonMemoryLoc2); // use current time and 2 random ints as seed for random generator

    int x = treasureX;
    int y = treasureY;
    bool roomsLeft = true;
    vector<int> checked;    // Create a vector of checked rooms.
    while(roomsLeft){
        Room room = dungeon->getRoom(x, y);
        checked.push_back((y * sizeX) + x);
        vector<int> doors;
        int nextRoom;
        for (int i = 0; i < 4; i ++){
            if (room.getDoor(i)){doors.push_back(i);}
        }
        if (doors.size() == 0){roomsLeft = false;}
        else{
            bool unique = false;
            while (!unique){
                int random_integer = rand() % doors.size();
                int direction = doors.at(random_integer);
                nextRoom = nextIndex(x, y, direction);
                bool found = false;
                for (int iterator : checked){
                    if (iterator == nextRoom){
                        found = true;
                        break;
                    }
                }
                if (!found) {unique = true;}
                else{
                    doors.erase(doors.begin() + random_integer);
                    if (doors.size() == 0){
                        roomsLeft = false;
                        break;
                    }
                }
            }
            if (roomsLeft){
                x = nextRoom % sizeX;
                y = (nextRoom - x) / sizeX;
            }
        }
    }
    dungeon->setSpawn((y * sizeX) + x);

}




