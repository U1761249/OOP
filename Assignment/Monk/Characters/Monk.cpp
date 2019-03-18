#include <iostream>
#include "BaseCharacter.h"
#include "Monk.h"
#include "../Dungeon/Dungeon.h"

using namespace std;

void Monk::place(){
    Dungeon *dungeon = dungeon->getInstance();
    setCurrentRoom(dungeon->getSpawn());
}

void Monk::move(int direction) {
    Dungeon *dungeon = dungeon->getInstance();
    int index = getCurrentRoom();
    int x = index % dungeon->getX();
    int y = (index - x) / dungeon->getY();

    switch (direction){
        case 0 : //North
            y = y - 1;  // Go up 1 row.
            break;
        case 1 : //East
            x = x + 1;        // Go right 1 room.
            break;
        case 2 : //South
            y = y + 1;  // Go down 1 row.
            break;
        case 3 : //West
            x = x - 1;       // Go left 1 room.
            break;
    }

    currentRoom = (y * dungeon->getX()) + x;
}

void Monk::pray() {
    if (getHealth() < getMaxHealth()){
        if (getPrayersLeft() <= 0){
            cout << "You have prayed too many times and the gods do not hear your pleas!" << endl;

        }
        else {
            setHealth(getMaxHealth());
            cout << "You successfully pray and the gods heal your wounds." << endl;
            cout << "You have " << getPrayersLeft() << " prayers left." << endl;
        }
    }
    else {
        cout << "You are already at full health..." << endl;
    }

}