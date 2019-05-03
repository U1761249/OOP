//
// Created by ATBir on 21/02/2019.
//

#include <time.h>
#include "Combat.h"
#include "../Characters/Monk.h"
#include "../Dungeon/Dungeon.h"
#include "../FileOut.h"
#include <unistd.h>

/**
 * Constructor of a Combat class.
 * Used as a controller to control the fight.
 */
Combat::Combat() {
    Monk *player = player->getInstance();
    Dungeon *dungeon = dungeon->getInstance();
    monster = dungeon->getRoom(player->getCurrentRoom()).getMonster();
}

/**
 * Start a fight between the Player and the Monster.
 * Player is created by getting the instance.
 * Monster is a pass by Value (a copy) that is removed elsewhere after it is defeated.
 */
void Combat::startFight() {

    Monk *player = player->getInstance();
    FileOut *print = print->getInstance();

    int order = player->getSpeed() - monster.getSpeed(); // 1 = Player  -1 = Monster
    usleep(1000000);
    print->toPrintln("You are fighting ");
    monster.desc();  // Display the statistics of the monster encountered.
    usleep(1000000);
    if (order > 0){print->toPrintln("You will perform an action FIRST! ");}
    else if (order == 0){print->toPrintln("You will perform an action AT THE SAME TIME! ");}
    else if (order < 0){print->toPrintln("You will perform an action SECOND! ");}
    else {print->toPrintln("Something weird happened and I can't explain it...");}
    cout << " \n";
    usleep(1000000);
    while (player->alive() && monster.alive()){ // Fight until one character dies.
        usleep(1000000);
        print->toPrintln("You have: " + to_string(player->getHealth()) + " Health out of " + to_string(player->getMaxHealth()));
        usleep(1000000);
         print->toPrintln("Monster has: " + to_string(monster.getHealth()) + " Health out of " + to_string(monster.getMaxHealth()));
        usleep(1000000);
        if (order == 0 | order == 1){
            playerAction();
            if (monster.alive() | monster.getSpeed() == player->getSpeed()){
                usleep(1000000);
                monsterAction();
            }

        }
        else{
            monsterAction();
            if (player->alive() | player->getSpeed() == monster.getSpeed()) {
                usleep(1000000);
                playerAction();
            }
        }
    }
    if (player->alive()) {
        print->toPrintln("You Won!");
        player->playerKill();
    }
    else print->toPrintln("OH NO! You died. ")
    ;
}

/**
 * Function used to attack another character.
 * @param offense integer to specify who is attacking.
 */
void Combat::attack(int offense){   // 0 - Player   1 - Monster
    Monk *player = player->getInstance();
    FileOut *print = print->getInstance();

    if (offense == 0){  // Player is attacking
        print->toPrintln( "You attempt to attack the beast...");
        if (randomBool()){
            print->toPrintln("The attack HIT and dealt " + to_string(player->getStrength()) + " damage.");
            monster.takeDamage(player->getStrength());
        }
        else {print->toPrintln("You missed! ");}
    }
    else{               // Monster is attacking
        print->toPrintln("The monster winds up for an attack...");
        if (randomBool()){
            print->toPrintln("The attack HIT and dealt " + to_string(monster.getStrength()) + " damage.");
            player->takeDamage(monster.getStrength());
        }
        else {print->toPrintln("The monster missed! ");}
    }
}

/**
 * Function used to heal a target.
 * @param target integer of the character defending.
 */
void Combat::defend(int target){   // 0 - Player   1 - Monster
    Monk *player = player->getInstance();
    FileOut *print = print->getInstance();

    if (target == 0){
        print->toPrintln("You attempt to treat your wounds...");
        if (player->getHealth() == player->getMaxHealth()){print->toPrintln("You are already at full health!");}
        else{
            if (randomBool()){
                print->toPrintln("You successfully heal 1 health point.");
                player->heal(1);
            }
            else {print->toPrintln("In the moment, your wounds were too hard to treat.");}
        }
    }
    else{
        print->toPrintln("The monster attempts to treat it's wounds...");
        if (monster.getHealth() == monster.getMaxHealth()){print->toPrintln("The monster is already at full health!");}
        else{
            if (randomBool()){
                print->toPrintln("The monster successfully heals 1 health point.");
                monster.heal(1);
            }
            else {print->toPrintln("The monster failed to heal, and cries out in frustration.");}
        }
    }

}

/**
 * This is the function used by the player to register an action.
 * Takes an input and checks that it is a digit, and compares it to the valid inputs.
 */
void Combat::playerAction() {
    FileOut *print = print->getInstance();

    print->toPrintln("What will you do? You can:");
    print->toPrintln("[7] Attack [9] Defend");

    string sInput;
    int input;
    bool valid = false;
    do{
        string sInput;
        cin >> sInput;
        if (sInput.find("kill") != string::npos) {  // KILL command to end fight early (for development)
            monster.setHealth(0);
            break;
        }

        else if (!isNumber(sInput)){print->toPrintln("Invalid Input - MUST BE A SINGLE POSITIVE DIGIT");}

        else {
            input = stoi(sInput);   // Convert valid string to int
            valid = true;
        }
        switch (input) {
            case 7 :
                attack(0);
                break;
            case 9 :
                defend(0);
                break;
            default:
                print->toPrintln("Invalid action");
                valid = false;
                break;
        }
    }while (!valid);
}

/**
 * Generate the action performed by the monster.
 * The monster will always attack at full health.
 * The monster has a 50% chance of either action below full health
 */
void Combat::monsterAction() {
    if (monster.getHealth() == monster.getMaxHealth()){attack(1);}  // Never try to heal while at full health.
    else{
        if (randomBool()){attack(1);}   // 50% to attack
        else{defend(1);}                // 50% to defend
    }

}

/**
 * This function checks that the user input can be converted to an integer.
 * @param s string to be checked.
 * @return True if all characters are Digits.
 */
bool Combat::isNumber(string s){
    bool isNumber = false;
    if (s.size() == 1){
        if (isdigit(s[0])){
            isNumber = true;
        }
    }
    return isNumber;
}

/**
 * Generate a random Bool value.
 * Used to reduce redundancy within this class.
 * @return 50% true, 50% false.
 */
bool Combat::randomBool(){
    int dungeonMemoryLoc = reinterpret_cast<int>(&dungeonMemoryLoc);    // Integer = integer's location as an integer.
    int dungeonMemoryLoc2 = reinterpret_cast<int>(&dungeonMemoryLoc2);
    srand(time(nullptr) * dungeonMemoryLoc % dungeonMemoryLoc2); // use current time and 2 random ints as seed for random generator
    return rand() % 2;
}