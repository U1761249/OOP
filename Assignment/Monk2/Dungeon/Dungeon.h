//
// Created by ATBir on 19/02/2019.
//

#ifndef MONK_DUNGON_H
#define MONK_DUNGON_H

#include "DungeonSuper.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Define the singleton class of Dungeon.
 * Subclass of DungeonSuper to allow for the Dungeon class to be dedicated to being a singleton.
 */
class Dungeon : public DungeonSuper {

    static Dungeon *instance;

    // Private constructor that should only be called by getInstance() if no instance exists.
    Dungeon(int size);
    Dungeon();  // Should never be used - create a small dungeon rather than crash.



public:

    /**
     * Get the instance of the dungeon (This method is used to create it)
     * @param size of the dungeon.
     */
    static Dungeon *getInstance(int size) {
        if (!instance) {
            instance = new Dungeon(size);
            cout << "New instance created \n";
        } else { cout << "Dungeon already exists \n"; }
        return instance;
    }

    /**
     * Get the instancec of the dungeon (This method can never create the dungeon).
     */
    static Dungeon *getInstance(){return instance;}

    /**
     * Generate the dungeon.
     */
    void generate();


};

#endif //MONK_DUNGON_H
