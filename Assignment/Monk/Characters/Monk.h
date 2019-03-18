//
// Created by ATBir on 19/02/2019.
//

#ifndef MONK_MONK_H
#define MONK_MONK_H
#include <string>

using namespace std;

#include "BaseCharacter.h"
#include "../Dungeon/Room.h"

class Monk : public BaseCharacter {
    int currentRoom;
    int prayersLeft;
    int killCount;

    static Monk* instance;

    // Private constructor so that no objects can be created.
    Monk(string name, string desc) {
        setName(name);
        setHealth(15);
        setMaxHealth(this->getHealth());
        setStrength(3);
        setSpeed(2);
        setDesc(desc);
        prayersLeft = 5;
        killCount = 0;
    }

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
    static Monk* getInstance(string name, string desc) {    // Lazy Initialization.
        if (!instance){instance = new Monk(name, desc);}
        return instance;
    }
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

    void move(int direction);

};



#endif //MONK_MONK_H
