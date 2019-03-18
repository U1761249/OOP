//
// Created by ATBir on 21/02/2019.
//

#include <time.h>
#include "Combat.h"
#include "../Characters/Monk.h"
#include "../Dungeon/Dungeon.h"
#include <unistd.h>


Combat::Combat() {
    Monk *player = player->getInstance();
    Dungeon *dungeon = dungeon->getInstance();
    monster = dungeon->getRoom(player->getCurrentRoom()).getMonster();
}

void Combat::startFight() {

    Monk *player = player->getInstance();

    int order = player->getSpeed() - monster.getSpeed(); // 1 = Player  -1 = Monster
    usleep(1000000);
    cout << "You are fighting ";
    monster.desc();  // Display the statistics of the monster encountered.
    usleep(1000000);
    if (order > 0){cout << "You will perform an action FIRST! \n";}
    if (monster.getSpeed() == player->getSpeed()){cout << "You will perform an action AT THE SAME TIME! \n";}
    else{cout << "You will perform an action SECOND! \n";}
    cout << " \n";
    usleep(1000000);
    while (player->alive() && monster.alive()){
        usleep(1000000);
        cout << "You have: " << player->getHealth() << " Health out of " << player->getMaxHealth() << endl;
        usleep(1000000);
        cout << "Monster has: " <<monster.getHealth() << " Health out of " << monster.getMaxHealth() << endl;
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
    if (player->alive()) cout << "You Won! \n";
    else cout << "OH NO! You died. \n";
}

void Combat::attack(int offense){   // 0 - Player   1 - Monster
    Monk *player = player->getInstance();

    if (offense == 0){  // Player is attacking
        cout << "You attempt to attack the beast...\n";
        if (randomBool()){
            cout << "The attack HIT and dealt " << player->getStrength() << " damage.\n";
            monster.takeDamage(player->getStrength());
        }
        else {cout << "You missed! \n";}
    }
    else{               // Monster is attacking
        cout << "The monster winds up for an attack...\n";
        if (randomBool()){
            cout << "The attack HIT and dealt " << monster.getStrength() << " damage.\n";
            player->takeDamage(monster.getStrength());
        }
        else {cout << "The monster missed! \n";}
    }
}

void Combat::defend(int target){   // 0 - Player   1 - Monster
    Monk *player = player->getInstance();

    if (target == 0){
        cout << "You attempt to treat your wounds... \n";
        if (player->getHealth() == player->getMaxHealth()){cout << "You are already at full health! \n";}
        else{
            if (randomBool()){
                cout << "You successfully heal 1 health point. \n";
                player->heal(1);
            }
            else {cout << "In the moment, your wounds were too hard to treat. \n";}
        }
    }
    else{
        cout << "The monster attempts to treat it's wounds... \n";
        if (monster.getHealth() == monster.getMaxHealth()){cout << "The monster is already at full health! \n";}
        else{
            if (randomBool()){
                cout << "The monster successfully heals 1 health point. \n";
                monster.heal(1);
            }
            else {cout << "The monster failed to heal, and cries out in frustration. \n";}
        }
    }

}

void Combat::playerAction() {
    cout << "What will you do? You can: \n";
    cout << "[7] Attack [9] Defend\n";

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

        else if (!isNumber(sInput)){cout << "Invalid Input - MUST BE A SINGLE POSITIVE DIGIT \n";}

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
                cout << "Invalid action \n";
                valid = false;
                break;
        }
    }while (!valid);
}

void Combat::monsterAction() {
    if (monster.getHealth() == monster.getMaxHealth()){attack(1);}  // Never try to heal while at full health.
    else{
        if (randomBool()){attack(1);}   // 50% to attack
        else{defend(1);}                // 50% to defend
    }

}

bool Combat::isNumber(string s){
    bool isNumber = false;
    if (s.size() == 1){
        if (isdigit(s[0])){
            isNumber = true;
        }
    }
    return isNumber;
}

bool Combat::randomBool(){
    int dungeonMemoryLoc = reinterpret_cast<int>(&dungeonMemoryLoc);    // Integer = integer's location as an integer.
    int dungeonMemoryLoc2 = reinterpret_cast<int>(&dungeonMemoryLoc2);
    srand(time(nullptr) * dungeonMemoryLoc % dungeonMemoryLoc2); // use current time and 2 random ints as seed for random generator
    return rand() % 2;
}