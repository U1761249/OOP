//
// Created by ATBir on 11/03/2019.
//

#include "Run.h"
#include "../Characters/Monk.h"
#include "../Dungeon/Dungeon.h"
#include "Movement.h"
using namespace std;

Monk * Monk::instance = 0;
Dungeon * Dungeon::instance = 0;

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

void Run::setup() {
        {
        Monk *player = player->getInstance();

        int size = 0;

        cout << endl << "This game is best played with a NUM PAD \n";
        cout << "Options will appear as [key] function.\n";

        cout <<"What size dungeon do you want to tackle? \n";
        cout << "[1] Small, [2] Medium, or [3] Large \n";
        int response;
        bool validResponse = false;
        do {
            cin >> response;
            switch (response){
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
                    cout << response << " was not a valid response. \n";
                    cout << "Response should be [1] Small, [2] Medium, or [3] Large \n";
            }
        } while (!validResponse);

        Dungeon *dungeon = dungeon->getInstance(size); // 0 small  1 medium  2 large
        dungeon->generate();
        player->place();
    }
}