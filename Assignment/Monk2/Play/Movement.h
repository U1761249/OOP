//
// Created by ATBir on 11/03/2019.
//

#ifndef MONK_MOVEMENT_H
#define MONK_MOVEMENT_H
#include <cstdio>
#include "string"
using namespace std;

/**
 * Define the Movement class to control the movement of the player throug the dungeon
 * and trigger necessary actions when they do so.
 */
class Movement {
public:
    void move(int index);

private:
    void displayDoors(int index);
    int validInputMove(int index);


    bool isNumber(string s);

    int nextIndex(int x, int y, int direction);

};


#endif //MONK_MOVEMENT_H
