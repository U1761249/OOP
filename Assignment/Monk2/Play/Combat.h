//
// Created by ATBir on 21/02/2019.
//

#ifndef MONK_COMBAT_H
#define MONK_COMBAT_H


#include "../Characters/Monster.h"
#include "../Characters/Monk.h"
#include "../Dungeon/Dungeon.h"

/**
 * Define the Combat class.
 * Used to control the combat mechanics of the game.
 */
class Combat {

public:
    Combat();

    void startFight();

private:

    void attack(int offense);
    void defend(int target);

    void playerAction();

    void monsterAction();

    bool isNumber(string s);

    bool randomBool();


    Monster monster;

};


#endif //MONK_COMBAT_H
