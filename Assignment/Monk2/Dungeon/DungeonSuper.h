//
// Created by ATBir on 05/03/2019.
//

#ifndef MONK_DUNGEONSUPER_H
#define MONK_DUNGEONSUPER_H

#include "Room.h"
#include <iostream>
#include <vector>

/**
 * An ABSTRACT Super class of Dungeon that stores the functionality of Dungeon.
 * This is done as storing this in Dungeon itself causes issues including:
 *      The Dungeon forgets the contents of SizeX and SizeY.
 *      The Dungeon cannot alter itself.
 */
class DungeonSuper {

public:
    int getX(){return sizeX;}
    void setX(int x){sizeX = x;}

    int getY(){ return sizeY;}
    void setY(int y){sizeY = y;}

    int getSize(){return rooms.size();}
    virtual void setRoomsSize(int x, int y){rooms.resize(x*y);}
    virtual void setSize(int size);

    Room getRoom(int x, int y);
    Room getRoom(int index);
    virtual void setRoom(int x, int y, int type);

    virtual void setNullRoom();

    virtual void setDoor(int index, int direction, bool value);

    int getSpawn(){ return spawnIndex;}
    virtual void setSpawn(int index);

    bool getWin(){ return win;}
    virtual void setWin(bool value){win = value;}

    int clearedCount(){ return cleared;}
    void roomCleared();

    void toString();

    void exit();

private:
    int sizeX = 4;
    int sizeY = 4;
    int spawnIndex = 0; //The index where the monk will spawn.
    bool win = false;
    int cleared = 0;

    vector<Room> rooms; // Vector that holds all of the rooms within the dungeon.
    // Room (3, 2) would be at index 15 in a 6X6
    // (y * sizeX) + x = target room
};

#endif //MONK_DUNGEONSUPER_H
