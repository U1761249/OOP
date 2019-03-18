//
// Created by ATBir on 19/02/2019.
//

#include "Dungeon.h"
#include "DungeonGenerator.h"


    Dungeon::Dungeon(int size) {
        setSize(size);

    for (int i = 0; i < getX() * getY(); i++){
        setNullRoom();
    }
}

    Dungeon::Dungeon() { // Should never be used, creates a small dungeon rather than crashing
        this->setSize(0);
        setRoomsSize(getX(), getY());
    }

    void Dungeon::generate() {
        DungeonGenerator *generator = new DungeonGenerator(getX(), getY());
        do {
            generator->startGenerating();
        } while (generator->getRoomCount() < 4);

    }



