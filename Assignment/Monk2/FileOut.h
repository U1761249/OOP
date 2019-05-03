//
// Created by ATBir on 19/03/2019.
//

#include <iostream>
#include <time.h>
#include <fstream>

#ifndef MONK2_PRINT_H
#define MONK2_PRINT_H

#endif //MONK2_PRINT_H

using namespace std;

/**
 * Define the FileOut class used to print to a file and the console.
 */
class FileOut {
    string filename;

    void setFilename(string value){this->filename = value;}

    static FileOut *instance;

    // Private constructor that should only be called by getInstance() if no instance exists.
    FileOut();

public:
    static FileOut *getInstance() {
        if (!instance) {
            instance = new FileOut();
        }
        return instance;
    }

    void toPrintln(string value);
    void toPrint(string value);

    void storeInput(string input);

};