//
// Created by ATBir on 19/02/2019.
//

#ifndef MONK_DUNGON_H
#define MONK_DUNGON_H

#include "DungeonSuper.h"
#include <iostream>
#include <vector>

using namespace std;

class Dungeon : public DungeonSuper {

    static Dungeon *instance;

    // Private constructor that should only be called by getInstance() if no instance exists.
    Dungeon(int size);
    Dungeon();  // Should never be used - create a small dungeon rather than crash.



public:
    static Dungeon *getInstance(int size) {
        if (!instance) {
            instance = new Dungeon(size);
            cout << "New instance created \n";
        } else { cout << "Dungeon already exists \n"; }
        return instance;
    }

    static Dungeon *getInstance(){return instance;}

    void generate();


};

#endif //MONK_DUNGON_H
