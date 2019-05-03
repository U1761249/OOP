#include <iostream>
#include "BaseCharacter.h"
#include "Monk.h"
#include "../Dungeon/Dungeon.h"
#include "../FileOut.h"

using namespace std;


/**
 * Place the monk in a spawn room.
 */
void Monk::place(){
    Dungeon *dungeon = dungeon->getInstance();
    setCurrentRoom(dungeon->getSpawn());
}

/**
 * Allow the monk to pray in an empty room to heal all damage.
 * The monk can only do this 5 times.
 */
void Monk::pray() {
    FileOut *print = print->getInstance();

    if (getHealth() < getMaxHealth()){
        if (getPrayersLeft() <= 0){
            print->toPrintln("You have prayed too many times and the gods do not hear your pleas!");

        }
        else {
            setHealth(getMaxHealth());
            print->toPrintln("You successfully pray and the gods heal your wounds.");
            setPrayersLeft(getPrayersLeft()-1);
            print->toPrintln("You have " + to_string(getPrayersLeft()) + " prayers left.");
        }
    }
    else {
        print->toPrintln("You are already at full health...");
    }

}