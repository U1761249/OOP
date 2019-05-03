//
// Created by ATBir on 19/02/2019.
//

#ifndef MONK_BASECHARACTER_H
#define MONK_BASECHARACTER_H
#include <string>
#include <iostream>
using namespace std;

/**
 * This is the Base class used for all characters as they have shared characteristics.
 * This is abstract as there can never be an object of type BaseCharacter.
 */
class BaseCharacter {
public:
    string getName(){return name;}
    virtual void setName(string value){name = value;}
    int getHealth(){ return health;}
    virtual void setHealth(int value){health = value;}
    int getMaxHealth(){ return maxhealth;}
    virtual void setMaxHealth(int value){maxhealth = value;}
    int getStrength(){ return strength;}
    virtual void setStrength(int value){strength = value;}
    int getSpeed(){ return speed;}
    virtual void setSpeed(int value){speed = value;}
    string getDesc(){ return description;}
    virtual void setDesc(string value){description = value;}

    bool alive(){ return this->health > 0;}

    void takeDamage(int damage){health = health - damage;}
    void heal(int value){health = health + value;}

    string toString(){
        return  "[Name] = " + getName() +
                " [Health] = " + to_string(getHealth()) +
                " [Speed] = " + to_string(getSpeed()) + "\n" ;
    }

private:
    string name;
    int health;
    int maxhealth;
    int strength;
    int speed;
    string description;

};


#endif //MONK_BASECHARACTER_H