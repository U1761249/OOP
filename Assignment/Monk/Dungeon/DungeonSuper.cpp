//
// Created by ATBir on 05/03/2019.
//

#include <sstream>
#include "DungeonSuper.h"
#include "DungeonGenerator.h"
#include "../Characters/Monk.h"


void DungeonSuper::setSize(int size) {
    switch (size){
        case 0 :    // Small Dungeon.   4X4
            this->setX(4);
            this->setY(4);
            break;
        case 1 :    // Medium Dungeon.  6X4
            this->setX(6);
            this->setY(4);
            break;
        case 2 :    // Large Dungeon.   6X6
            this->setX(6);
            this->setY(6);
            break;
        default:
            setSize(0); // Small by default.
            break;
    }
}

Room DungeonSuper::getRoom(int x, int y) {
    Room toReturn;
    int index = (y * sizeX) + x;
    if (index >= this->getSize()){cout << "Index is outside the bounds of the vector. \n";}
    else toReturn = rooms.at(index);
    return toReturn;
}

Room DungeonSuper::getRoom(int index) {
    Room toReturn;
    if (index >= this->getSize()){cout << "Index is outside the bounds of the vector. \n";}
    else toReturn = rooms.at(index);
    return toReturn;
}

void DungeonSuper::setDoor(int index, int direction, bool value){
    rooms.at(index).setDoor(direction, value);
}

void DungeonSuper::setRoom(int x, int y, int type) {
    int index = (y * sizeX) + x;
    Room room(x, y, type);
    rooms.at(index) = room;
}

void DungeonSuper::setNullRoom() {
    rooms.emplace_back();
}

void DungeonSuper::toString() {
    cout << sizeX << " X " << sizeY << " Dungeon\n";
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x ++){
            int index = (y * sizeX) + x;
            Room room = rooms.at(index);
            if (room.getX() == -1){cout << "[Emp]";}
            else{
                string type;
                switch (room.getType()){
                    case 0:
                        if (!room.getCleared()){
                            if (room.getMonsterRoom()) type = "M";  // M monster  E empty
                            else type = "E";
                        }
                        else type =  "C";                           // C cleared
                        break;
                    case 1 :
                        type = "T";
                        break;
                    case 2 :
                        type = "S";
                        break;
                }

                cout << "[ " << type << " ]";
            }
            if (room.getDoor(1)){   cout << "-";}
            else cout << " ";
        }
        cout << " " << endl;
        for (int x = 0; x < sizeX; x ++){
            cout << "  ";
            if (rooms.at((y * sizeX) + x).getDoor(2)){
                cout << "|";
            }
            else { cout << " ";}
            cout << "   ";
        }
        cout << " " << endl;
    }
}

void DungeonSuper::setSpawn(int index) {
    spawnIndex = index;
    rooms.at(index).setMonsterRoom(false);
    rooms.at(index).setType(2);
}

void DungeonSuper::exit() {
    Monk *player = player->getInstance();
    if (rooms.at(player->getCurrentRoom()).getType() == 1){
        setWin(true);
    }
}

void DungeonSuper::roomCleared() {
    Monk *player = player->getInstance();
    int index = player->getCurrentRoom();
    cleared ++;
    rooms.at(index).setCleared();
    rooms.at(index).setMonsterRoom(false);
    rooms.at(index).setMonster(new Monster()); // Populate with a null monster
}
