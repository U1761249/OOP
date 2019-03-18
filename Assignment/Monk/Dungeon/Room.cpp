//
// Created by ATBir on 19/02/2019.
//

#include "Room.h"
#include <random>
#include <time.h>

/**
 * Default constructor - SHOULD NOT BE USED TO GENERATE A VALID ROOM
 */
Room::Room(){
    this->created = false;
    this->x = -1;
    this->y = -1;
}

/**
 * Proper constructor for a room.
 * @param x the room's X co-ordinate.
 * @param y the room's Y co-ordinate.
 */
Room::Room(int x, int y, int roomType) {
    this->x = x;
    this->y = y;
    this->type = roomType;
    this->created = true;
    this->cleared = false;
    this->monsterRoom = false;
    for (int i = 0; i < 4; i++){doors[i] = false;}
    setupRoom(roomType);
}

/**
 * This is a getter for a room's monster.
 * @return Monster if there is one.
 * @return NULL if no monster is in the room.
 */
Monster Room::getMonster() {
    if (monster.getName() != ""){return monster;}
    else{ return -1;}
}

/**
 * Set up a room based on it's type.
 * Can be easily expended for more rooms.
 * @param type - the type of room to be set up.
 */
void Room::setupRoom(int type) {
    switch (type){
        case 0 :    // Normal room
            this->generateMonster();
            break;
        case 1 :    // Treasure room
            this->monsterRoom = false;
            break;
        case 2 :    // Spawn room
            this->monsterRoom = false;
            break;
    }
}

/**
 * Allocate a monster to the room.
 * @param monster to be added to the room.
 */
void Room::setMonster(Monster *monster) {
    this->monster = *monster;
}

/**
 * Generate a monster (or none) to be added to the room.
 */
void Room::generateMonster() {

    int dungeonMemoryLoc = reinterpret_cast<int>(&dungeonMemoryLoc);    // Integer = integer's location as an integer.
    int dungeonMemoryLoc2 = reinterpret_cast<int>(&dungeonMemoryLoc2);
    srand(time(nullptr) * dungeonMemoryLoc % dungeonMemoryLoc2); // use current time and 2 random ints as seed for random generator
    int random_integer = rand() % 6;

    if (random_integer % 2 == 1)// generates a monster 50% of the time.
    {this->setMonster(new Monster(random_integer));
    this->monsterRoom = true;}
}

void Room::setDoors(bool newDoors[]){
    for (int i = 0; i < 4; i++){
        doors[i] = newDoors[i];
    }
}

