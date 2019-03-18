//
// Created by ATBir on 11/03/2019.
//

#ifndef MONK_MOVEMENT_H
#define MONK_MOVEMENT_H
#include <cstdio>
#include "string"
using namespace std;

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
