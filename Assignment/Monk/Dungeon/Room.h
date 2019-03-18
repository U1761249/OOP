//
// Created by ATBir on 19/02/2019.
//

#ifndef MONK_ROOM_H
#define MONK_ROOM_H

#include "../Characters/Monster.h"

class Room {
public:
    Room();
    Room(int x, int y, int roomType);

    //  Lots of Getter and Setter functions.
    void setupRoom(int type);
    int getX() const {return x;}
    int getY() const {return y;}
    int getType()const { return type;}
    void setX(int newX){x = newX;}
    void setY(int newY){y = newY;}
    void setType(int newType){type = newType;}

    bool getMonsterRoom() const {return monsterRoom;}
    void setMonsterRoom(bool newValue){monsterRoom = newValue;}
    Monster getMonster();
    void setMonster(Monster *monster);

    bool getDoor(int direction){ return reinterpret_cast<bool *>(doors[direction]);}
    void setDoor(int direction, bool value){doors[direction] = value;}
    void setDoors(bool newDoors[]);

    bool isCreated(){return created;}
    bool getCleared(){return cleared;}
    void setCleared(){cleared = true;}

private:
    bool created;
    bool cleared;
    int x;
    int y;
    int type;
    bool monsterRoom;
    Monster monster;
    bool doors[4]; // [North, East, South, West] True - door  False - wall

    void generateMonster();

};

#endif //MONK_ROOM_H
