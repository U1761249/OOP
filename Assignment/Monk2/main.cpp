#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include "Play/Run.h"
#include "Characters/Monk.h"
#include "FileOut.h"

using namespace std;

/**
 * Main method to begin the execution of the game.
 */
int main() {

    Run *run = new Run;

    string name, desc;
    cout << "What is the name of the monk?" << endl;
    std::getline(std::cin, name);
    cout << "Describe the monk" << endl;
    std::getline(std::cin, desc);

    Monk *player = player->getInstance(name, desc);

    run->start();

    FileOut *print = print->getInstance();

    print->toPrintln("Press any key to continue . . .");
    _getch(); // wait for keypress

    return 0;
}