//
// Created by ATBir on 11/03/2019.
//

#include "Run.h"
#include "../Characters/Monk.h"
#include "../Dungeon/Dungeon.h"
#include "Movement.h"
#include "../FileOut.h"

using namespace std;

Monk * Monk::instance = 0;
Dungeon * Dungeon::instance = 0;
FileOut * FileOut::instance = 0;

/**
 * Start a loop to run the game for the life of the player or until the treasure room is found.
 */
void Run::start() {

    Movement *move = new Movement;

    Monk *player = player->getInstance();

    setup();

    Dungeon *dungeon = dungeon->getInstance();

    dungeon->toString();
    while (player->alive() && !dungeon->getWin()){
        move->move(player->getCurrentRoom());
    }
}

/**
 * Set up the game.
 * Take and verify an input from the user.
 * Use that input to create a dungeon of a specific size.
 */
void Run::setup() {
    Monk *player = player->getInstance();
    FileOut *print = print->getInstance();

    int size = 0;

    print->toPrintln("This game is best played with a NUM PAD \nOptions will appear as [key] function.");

    print->toPrintln("What size dungeon do you want to tackle?");
    print->toPrintln("[1] Small, [2] Medium, or [3] Large");

    string sInput;
    int response;
    bool validInput;
    do{
        validInput = false;
        sInput = "";
        response = 0;
        std::getline(std::cin, sInput);
        if (!isNumber(sInput)) { print->toPrintln("Invalid Input - MUST BE A SINGLE POSITIVE DIGIT"); }
        else {
            response = stoi(sInput);   // Convert validInput string to int
            validInput = true;
        }
    } while (!validInput);

        bool validResponse = false;
        do {
            cin >> response;
            print->storeInput(to_string(response));
            switch (response) {
                case 1 :
                    size = 0;
                    validResponse = true;
                    break;
                case 2 :
                    size = 1;
                    validResponse = true;
                    break;
                case 3 :
                    size = 2;
                    validResponse = true;
                    break;
                default:
                    print->toPrintln(to_string(response) + " was not a validInput response.");
                    print->toPrintln("Response should be [1] Small, [2] Medium, or [3] Large");
            }
        } while (!validResponse);

        Dungeon *dungeon = dungeon->getInstance(size); // 0 small  1 medium  2 large
        dungeon->generate();
        player->place();
}

/**
 * Check that an input is numerical.
 * @param s string to be checked.
 * @return True if all characters are digits.
 */
bool Run::isNumber(string s){
    bool isNumber = false;
    if (s.size() == 1){
        if (isdigit(s[0])){
            isNumber = true;
        }
    }
    return isNumber;
}