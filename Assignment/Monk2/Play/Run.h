//
// Created by ATBir on 11/03/2019.
//

#ifndef MONK_RUN_H
#define MONK_RUN_H
#include "string"
using namespace std;

/**
 * Define the class used to run the game.
 */
class Run {

public:
    void start();

private:
    void setup();
    bool isNumber(string s);

};


#endif //MONK_RUN_H
