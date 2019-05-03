//
// Created by ATBir on 05/03/2019.
//

#include <sstream>
#include "DungeonSuper.h"
#include "DungeonGenerator.h"
#include "../Characters/Monk.h"
#include "../FileOut.h"


/**
 * Set the length of the vector to the size of the dungeon to be created.
 * @param size of the desired dungeon.
 */
void DungeonSuper::setSize(int size) {
    switch (size){
        case 0 :    // Small Dungeon.   4X4
            this->setX(4);
            this->setY(4);
            break;
        case 1 :    // Medium Dungeon.  6X4
            this->setX(6);
            this->setY(4);
            break;
        case 2 :    // Large Dungeon.   6X6
            this->setX(6);
            this->setY(6);
            break;
        default:
            setSize(0); // Small by default.
            break;
    }
}

/**
 * Get the room at a desired index using the X and Y co-ordinates.
 * @param x of the room.
 * @param y of the room.
 * @return Room at the desired index.
 */
Room DungeonSuper::getRoom(int x, int y) {
    FileOut *print = print->getInstance();

    Room toReturn;
    int index = (y * sizeX) + x;
    if (index >= this->getSize()){print->toPrintln("Index is outside the bounds of the vector.");}
    else toReturn = rooms.at(index);
    return toReturn;
}

/**
 * Get the room at a desired index using a single integer index.
 * @param index of the desired room.
 * @return Room at the desired index.
 */
Room DungeonSuper::getRoom(int index) {
    FileOut *print = print->getInstance();

    Room toReturn;
    if (index >= this->getSize()){print->toPrintln("Index is outside the bounds of the vector.");}
    else toReturn = rooms.at(index);
    return toReturn;
}

/**
 * Set a room's door to a bool value in a direction.
 * @param index of the room that needs to be changed.
 * @param direction of the door that needs to be changed.
 * @param value the door needs to be set to.
 */
void DungeonSuper::setDoor(int index, int direction, bool value){
    rooms.at(index).setDoor(direction, value);
}

/**
 * Create a room at a given index in the vector.
 * @param x of the room to be created.
 * @param y of the room to be created.
 * @param type of room to be created.
 */
void DungeonSuper::setRoom(int x, int y, int type) {
    int index = (y * sizeX) + x;
    Room room(x, y, type);
    rooms.at(index) = room;
}

/**
 * Used to populate the dungeon with invalid rooms.
 * A 4X4 dungeon will always have 16 rooms, even if only 7 are playable.
 */
void DungeonSuper::setNullRoom() {
    rooms.emplace_back();
}

/**
 * Used to display the dungeon as a legible string the user can use.
 */
void DungeonSuper::toString() {
    FileOut *print = print->getInstance();
    string dungeonSize = to_string(sizeX) + " X " + to_string(sizeY) + " Dungeon";
    print->toPrintln(dungeonSize);

    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x ++){
            int index = (y * sizeX) + x;
            Room room = rooms.at(index);
            if (room.getX() == -1){print->toPrint("[Emp]");}
            else{
                string type;
                switch (room.getType()){
                    case 0:
                        if (!room.getCleared()){
                            if (room.getMonsterRoom()) type = "M";  // M monster  E empty
                            else type = "E";
                        }
                        else type =  "C";                           // C cleared
                        break;
                    case 1 :
                        type = "T";
                        break;
                    case 2 :
                        type = "S";
                        break;
                }

                print->toPrint("[ " + type + " ]");
            }
            if (room.getDoor(1)){   print->toPrint("-");}
            else print->toPrint(" ");
        }
        print->toPrintln(" ");
        for (int x = 0; x < sizeX; x ++){
            print->toPrint("  ");
            if (rooms.at((y * sizeX) + x).getDoor(2)){
                print->toPrint("|");
            }
            else { print->toPrint(" ");}
            print->toPrint("   ");
        }
        print->toPrintln(" ");
    }
}

/**
 * Used to set the spawn room of the dungeon.
 * @param index of the room to become the spawn room.
 */
void DungeonSuper::setSpawn(int index) {
    spawnIndex = index;
    rooms.at(index).setMonsterRoom(false);
    rooms.at(index).setType(2);
}

/**
 * Win condition of the dungeon upon entering the treasure room.
 */
void DungeonSuper::exit() {
    Monk *player = player->getInstance();
    if (rooms.at(player->getCurrentRoom()).getType() == 1){
        setWin(true);
    }
}

/**
 * Set the current room to cleared.
 * This prevents monsters from fighting after being killed.
 * This also gets displayed as [C] in the toString() method.
 */
void DungeonSuper::roomCleared() {
    Monk *player = player->getInstance();
    int index = player->getCurrentRoom();
    if (!rooms.at(index).getCleared()){
        cleared ++;
        rooms.at(index).setCleared();
        rooms.at(index).setMonsterRoom(false);
        rooms.at(index).setMonster(new Monster()); // Populate with a null monster
    }
}
