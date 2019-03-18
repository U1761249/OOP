//
// Created by ATBir on 21/02/2019.
//

#ifndef MONK_DUNGEONGENERATOR_H
#define MONK_DUNGEONGENERATOR_H

#include "Dungeon.h"
#include "Room.h"


class DungeonGenerator {

    int sizeX;
    int sizeY;
    int roomCount;

public:

    DungeonGenerator(int x, int y){
        sizeX = x;
        sizeY = y;
        roomCount = 0;
    }

    int getRoomCount(){ return roomCount;}

    void startGenerating();
    int nextIndex(int x, int y, int direction);

private:

    void generateDoors(int x, int y, int origin);
    bool checkDoors(int index, int direction);

    void newRoom(int destination, int origin);

    void setSpawn(int treasureX, int treasureY);
};


#endif //MONK_DUNGEONGENERATOR_H
