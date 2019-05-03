//
// Created by ATBir on 19/02/2019.
//

#include "Dungeon.h"
#include "DungeonGenerator.h"

/**
 * Constructor for dungeon to set the size of the dungeon.
 * @param size of the dungeon (SizeX * SizeY)
 */
Dungeon::Dungeon(int size) {
    setSize(size);

    for (int i = 0; i < getX() * getY(); i++){
        setNullRoom();
    }
}

/**
 * Default constructor for Dungeon.
 * This should never be used but generates a small dungeon rather than crashing.
 */
Dungeon::Dungeon() {
    this->setSize(0);
    setRoomsSize(getX(), getY());
}

/**
 * Generate the dungeon to fit within the given size.
 */
void Dungeon::generate() {
    DungeonGenerator *generator = new DungeonGenerator(getX(), getY());
    generator->startGenerating();


}


