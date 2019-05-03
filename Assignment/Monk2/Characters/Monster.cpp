//
// Created by ATBir on 21/02/2019.
//

#include "Monster.h"


/**
 * This is the main constructor for a monster.
 * All characters have a strength of 5 - any successful attack will deal 5 damage.
 * @param type - an integer dictating characteristics of the monster.
 * More monsters can be easily added by adding more case statements.
 * even numbers used to create empty rooms 50% of the time.
 */
Monster::Monster(int type) {

    switch (type) {
        case 1 :
            this->setName("[Goblin Monster]");
            this->setHealth(10);
            this->setMaxHealth(this->getHealth());
            this->setStrength(2);
            this->setSpeed(2);
            this->setDesc("A goblin of balanced health and speed.");
            break;

        case 3 :
            this->setName("[Imp Monster]");
            this->setHealth(10);
            this->setMaxHealth(this->getHealth());
            this->setStrength(2);
            this->setSpeed(3);
            this->setDesc("A fast but lightly armoured Imp.");
            break;

        case 5 :
            this->setName("[Troll Monster]");
            this->setHealth(20);
            this->setMaxHealth(this->getHealth());
            this->setStrength(4);
            this->setSpeed(1);
            this->setDesc("A slow but heavily armoured troll.");
            break;

        default :
            throw "Invalid Monster!";
    }
}
Monster::Monster() {
    this->setName("");
    this->setHealth(0);
    this->setStrength(0);
    this->setSpeed(0);
    this->setDesc("A null monster");
}
