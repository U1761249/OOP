//
// Created by ATBir on 19/02/2019.
//

#ifndef MONK_MONK_H
#define MONK_MONK_H
#include <string>

using namespace std;

#include "BaseCharacter.h"
#include "../Dungeon/Room.h"

/**
 * This is the class that defines the player character.
 * This is a singleton as there is only ever one character.
 */
class Monk : public BaseCharacter {
    int currentRoom;
    int prayersLeft;
    int killCount;

    static Monk* instance;

    /**
     * Private constructor that can only be called by getInstance.
     * @param name of the monk.
     * @param desc of the monk.
     */
    Monk(string name, string desc) {
        if (name == ""){setName("Monk");}
        else {setName(name);}
        setHealth(15);
        setMaxHealth(this->getHealth());
        setStrength(3);
        setSpeed(2);
        if (desc == ""){setDesc("A hooded monk from the monastery.");}
        else {setDesc(desc);;}
        prayersLeft = 5;
        killCount = 0;
    }

    /**
     * Default constructor of monk.
     * SHOULD NEVER BE USED IN NORMAL RUN TIME
     */
    Monk(){
        setName("Monk");
        setHealth(15);
        setMaxHealth(this->getHealth());
        setStrength(3);
        setSpeed(2);
        setDesc("This is you, a hooded monk from the Monastery.");
        prayersLeft = 5;
        killCount = 0;
    }

public:
    /**
     * Get the instance of Monk (This one is used to create monk too).
     * @param name of the monk.
     * @param desc of the monk
     * @return instance of the monk.
     */
    static Monk* getInstance(string name, string desc) {    // Lazy Initialization.
        if (!instance){instance = new Monk(name, desc);}
        return instance;
    }

    /**
     * Get the instance of the monk (Should never be used to create monk).
     * @return instanace of the monk.
     */
    static Monk* getInstance() {    // Lazy Initialization.
        if (!instance){instance = new Monk();}
        return instance;
    }

    void place();

    int getCurrentRoom(){ return currentRoom;}
    void setCurrentRoom(int index){currentRoom = index;}

    int getPrayersLeft(){return this->prayersLeft;}
    void setPrayersLeft( int count){prayersLeft = count; }

    int getKillCount(){return this->killCount;}
    void playerKill(){killCount ++;}
    void setKillCount( int count){killCount = count; }

    void pray();


};



#endif //MONK_MONK_H
