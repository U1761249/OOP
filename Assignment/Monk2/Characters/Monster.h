//
// Created by ATBir on 21/02/2019.
//

#ifndef MONK_MONSTER_H
#define MONK_MONSTER_H


#include "BaseCharacter.h"

/**
 * Define the subclass Monster - the place where all monsters come from.
 */
class Monster : public BaseCharacter{
public:
    Monster(int type);
    Monster();
    void desc(){cout << this->getDesc() << endl;}
};


#endif //MONK_MONSTER_H
