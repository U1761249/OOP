//
// Created by ATBir on 11/03/2019.
//

#include "Movement.h"
#include "../Characters/Monk.h"
#include "../Dungeon/Dungeon.h"
#include "../Dungeon/Room.h"
#include "Combat.h"

using namespace std;

void Movement::move(int index) {

    Monk *player = player->getInstance();
    Dungeon *dungeon = dungeon->getInstance();
    dungeon->roomCleared();

    int input = validInputMove(index);
    Room room = dungeon->getRoom(index);

    int nextLocation = nextIndex(room.getX(), room.getY(), input);
    Room nextRoom = dungeon->getRoom(nextLocation);

    player->setCurrentRoom(nextLocation);
    if (nextRoom.getMonsterRoom() && !nextRoom.getCleared()){   // Next room not cleared and has a monster

        Combat combat;
        cout << "        FIGHT! \n";
        combat.startFight();
    }
    else if (nextRoom.getType() == 1){ // treasureRoom
        cout << "        You found the Treasure Room" << endl;
        dungeon->exit();
    }

}

int Movement::validInputMove(int index){
    Monk *player = player->getInstance();

    Dungeon *dungeon = dungeon->getInstance();
    Room currentRoom = dungeon->getRoom(index);

    bool valid = false;
    string sInput;
    int input;
    int direction;

    do{
        displayDoors(index);
        sInput = "";
        cin >> sInput;
        if (!isNumber(sInput)){cout << "Invalid Input - MUST BE A SINGLE POSITIVE DIGIT \n";}
        else {
            input = stoi(sInput);   // Convert valid string to int
            switch(input) {
                case 8 :       // North
                    if (currentRoom.getDoor(0)){
                        direction = 0;
                        valid = true;
                    } else cout << "Invalid input \n";
                    break;
                case 6 :    // East
                    if (currentRoom.getDoor(1)){
                        direction = 1;
                        valid = true;
                    } else cout << "Invalid input \n";
                    break;
                case 2 :    // South
                    if (currentRoom.getDoor(2)){
                        direction = 2;
                        valid = true;
                    } else cout << "Invalid input \n";
                    break;
                case 4 :    // West
                    if (currentRoom.getDoor(3)){
                        direction = 3;
                        valid = true;
                    } else cout << "Invalid input \n";
                    break;
                case 1:
                    dungeon->toString();
                    break;
                case 3 :
                    if (!currentRoom.getMonsterRoom()){player->pray();}
                    else cout << "The corpse of a monster prevents you from praying here. \n";
                    break;
                case 5 :
                    cout << " " << endl;
                    cout << "You are " << player->getName() << ", " << player->getDesc() << endl;
                    cout << player->getName() << " has " << player->getHealth() << " health. \n";
                    cout << player->getName() << " has cleared " << dungeon->clearedCount() << " rooms. \n";
                    cout << player->getName() << " has " << player->getKillCount() << " kills this dungeon. \n";
                    cout << player->getName() << " is in room [" << currentRoom.getX() << "," << currentRoom.getY() << "] \n";
                    cout << player->getName() << " has " << player->getPrayersLeft() << " prayers left. \n";
                    cout << " " << endl;
                    break;
                default :
                    cout << "Invalid input \n";
            }
        }
    } while (!valid);
    return direction;
}

void Movement::displayDoors(int index) {
    Dungeon *dungeon = dungeon->getInstance();
    Room currentRoom = dungeon->getRoom(index);

    cout << "You are able to move: \n";
    for (int i = 0; i < 4; i ++){
        switch (i){
            case 0:
                if (currentRoom.getDoor(0))
                    cout << "[8] North ";
                break;
            case 1:
                if (currentRoom.getDoor(1))
                    cout << "[6] East ";
                break;
            case 2:
                if (currentRoom.getDoor(2))
                    cout << "[2] South ";
                break;
            case 3:
                if (currentRoom.getDoor(3))
                    cout << "[4] West ";
                break;
        }

    }
    cout << " " << endl;
    cout << "Or press [5] to see statistics [3] to pray or [1] for the map.\n";
}

bool Movement::isNumber(string s){
    bool isNumber = false;
    if (s.size() == 1){
        if (isdigit(s[0])){
            isNumber = true;
        }
    }
    return isNumber;
}

int Movement::nextIndex(int x, int y, int direction) {

    Dungeon *dungeon = dungeon->getInstance();

    switch (direction){
        case 0 : //North
            y = y - 1;  // Go up 1 row.
            break;
        case 1 : //East
            x = x + 1;        // Go right 1 room.
            break;
        case 2 : //South
            y = y + 1;  // Go down 1 row.
            break;
        case 3 : //West
            x = x - 1;       // Go left 1 room.
            break;
    }

    return (y * dungeon->getX()) + x;
}