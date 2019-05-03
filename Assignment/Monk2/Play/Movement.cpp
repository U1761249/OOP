//
// Created by ATBir on 11/03/2019.
//

#include "Movement.h"
#include "../Characters/Monk.h"
#include "../Dungeon/Dungeon.h"
#include "../Dungeon/Room.h"
#include "Combat.h"
#include "../FileOut.h"

using namespace std;

/**
 * Allow the user to move between rooms, and control the function after entering a room.
 * @param index of the current room.
 */
void Movement::move(int index) {

    Monk *player = player->getInstance();
    FileOut *print = print->getInstance();
    Dungeon *dungeon = dungeon->getInstance();
    dungeon->roomCleared(); // Set the current room to cleared once the player enters it for the first time.

    int input = validInputMove(index);
    Room room = dungeon->getRoom(index);

    int nextLocation = nextIndex(room.getX(), room.getY(), input);
    Room nextRoom = dungeon->getRoom(nextLocation);

    player->setCurrentRoom(nextLocation);   // Technically, this is where the player enters the next room.
    if (nextRoom.getMonsterRoom() && !nextRoom.getCleared()){   // Next room not cleared and has a monster

        Combat combat;
        print->toPrintln("        FIGHT! ");
        combat.startFight();
    }
    else if (nextRoom.getType() == 1){ // treasureRoom
        print->toPrintln("        You found the Treasure Room");
        dungeon->exit();
    }

}

/**
 * Check that the user's input is valid.
 * Check it is an integer.
 * Check that it is a valid action.
 * @param index of the current room.
 * @return direction that the user wants to move.
 */
int Movement::validInputMove(int index){
    Monk *player = player->getInstance();
    FileOut *print = print->getInstance();


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
        if (!isNumber(sInput)){print->toPrintln("Invalid Input - MUST BE A SINGLE POSITIVE DIGIT ");}
        else {
            input = stoi(sInput);   // Convert valid string to int
            switch(input) {
                case 8 :       // North
                    if (currentRoom.getDoor(0)){
                        direction = 0;
                        valid = true;
                    } else print->toPrintln("Invalid input");
                    break;
                case 6 :    // East
                    if (currentRoom.getDoor(1)){
                        direction = 1;
                        valid = true;
                    } else print->toPrintln("Invalid input ");
                    break;
                case 2 :    // South
                    if (currentRoom.getDoor(2)){
                        direction = 2;
                        valid = true;
                    } else print->toPrintln("Invalid input ");
                    break;
                case 4 :    // West
                    if (currentRoom.getDoor(3)){
                        direction = 3;
                        valid = true;
                    } else print->toPrintln("Invalid input");
                    break;
                case 1:
                    dungeon->toString();
                    break;
                case 3 :
                    if (!currentRoom.getMonsterRoom()){player->pray();}
                    else print->toPrintln("The corpse of a monster prevents you from praying here.");
                    break;
                case 5 :
                    print->toPrintln(" ");
                    print->toPrintln("You are " + player->getName() + ", " + player->getDesc());
                    print->toPrintln(player->getName() + " has " + to_string(player->getHealth()) + " health.");
                    print->toPrintln(player->getName() + " has cleared " + to_string(dungeon->clearedCount()) + " rooms.");
                    print->toPrintln(player->getName() + " has " + to_string(player->getKillCount()) + " kills this dungeon.");
                    print->toPrintln(player->getName() + " is in room [" + to_string(currentRoom.getX()) + "," + to_string(currentRoom.getY()) + "]");
                    print->toPrintln(player->getName() + " has " + to_string(player->getPrayersLeft()) + " prayers left.");
                    print->toPrintln(" ");
                    break;
                default :
                    print->toPrintln("Invalid input");
            }
        }
    } while (!valid);
    return direction;
}

/**
 * Display the doors of the current room (the valid inputs the program can have for this room).
 * @param index of the current room.
 */
void Movement::displayDoors(int index) {
    Dungeon *dungeon = dungeon->getInstance();
    Room currentRoom = dungeon->getRoom(index);
    FileOut *print = print->getInstance();


    print->toPrintln("You are able to move:");
    for (int i = 0; i < 4; i ++){
        switch (i){
            case 0:
                if (currentRoom.getDoor(0))
                    print->toPrint("[8] North ");
                break;
            case 1:
                if (currentRoom.getDoor(1))
                    print->toPrint("[6] East ");
                break;
            case 2:
                if (currentRoom.getDoor(2))
                    print->toPrint("[2] South ");
                break;
            case 3:
                if (currentRoom.getDoor(3))
                    print->toPrint("[4] West ");
                break;
        }

    }
    print->toPrintln(" ");
    print->toPrintln("Or press [5] to see statistics [3] to pray or [1] for the map.");
}

/**
 * Check that the user input is numerical.
 * @param s string input to be checked.
 * @return True if all characters are digits.
 */
bool Movement::isNumber(string s){
    bool isNumber = false;
    if (s.size() == 1){
        if (isdigit(s[0])){
            isNumber = true;
        }
    }
    return isNumber;
}

/**
 * Get the index of a room in a given direction.
 * @param x co-ordinate of the current room.
 * @param y co-ordinate of the current room.
 * @param direction from the current room.
 * @return index of the next room.
 */
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