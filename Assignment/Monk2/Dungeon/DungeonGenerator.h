//
// Created by ATBir on 21/02/2019.
//

#ifndef MONK_DUNGEONGENERATOR_H
#define MONK_DUNGEONGENERATOR_H

#include "Dungeon.h"
#include "Room.h"


/**
 * Define the Dungeon Generator used to create the layout of the dungeon and populate it with monsters.
 */
class DungeonGenerator {

    int sizeX;
    int sizeY;
    int roomCount;

public:

    /**
     * Public constructor of the DungeonGenerator
     * @param x size of the dungeon.
     * @param y size of the dungeon.
     */
    DungeonGenerator(int x, int y){
        sizeX = x;
        sizeY = y;
        roomCount = 0;
    }

    int getRoomCount(){ return roomCount;}

    void startGenerating();

    /**
     * Definition of the nextIndex used to get the index in a given direction.
     * @param x of the current room.
     * @param y of the current room.
     * @param direction from the current room.
     * @return index of the next room.
     */
    int nextIndex(int x, int y, int direction);

private:

    void generateDoors(int x, int y, int origin);
    bool checkDoors(int index, int direction);

    void newRoom(int destination, int origin);

    void setSpawn(int treasureX, int treasureY);
};


#endif //MONK_DUNGEONGENERATOR_H
