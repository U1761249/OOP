//
// Created by ATBir on 21/02/2019.
//

#ifndef MONK_MONSTER_H
#define MONK_MONSTER_H


#include "BaseCharacter.h"

class Monster : public BaseCharacter{
public:
    Monster(int type);
    Monster();
    void desc(){cout << this->getDesc() << endl;}
};


#endif //MONK_MONSTER_H
