#include <iostream>
#include <fstream>
#include <time.h>
#include "Play/Run.h"
#include "Characters/Monk.h"

using namespace std;

int main() {

    Run *run = new Run;

    string name, desc;
    cout << "What is the name of the monk?" << endl;
    std::getline(std::cin, name);
    cout << "Describe the monk" << endl;
    std::getline(std::cin, desc);

    Monk *player = player->getInstance(name, desc);

    run->start();

    return 0;
}