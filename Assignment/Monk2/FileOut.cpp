//
// Created by ATBir on 19/03/2019.
//
#include "FileOut.h"
#include "Characters/Monk.h"

/**
 * Constructor for the FileOut class.
 */
FileOut::FileOut(){
    Monk *player = player->getInstance();
    string tempFilename = player->getName();
    tempFilename.append("_");

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    char buffer [80];
    strftime (buffer,80,"%j %H %M %S",now);
    tempFilename.append(buffer);
    tempFilename.append(".txt");
    this->setFilename(tempFilename);

    ofstream myfile;
    myfile.open( filename.c_str(), ios::out | ios::app );
    if (myfile.is_open()){
        string name = player->getName();
        string desc = player->getDesc();
        myfile << name << endl;
        myfile << desc << endl;
        myfile.close();
    }

}

/**
 * Print command that writes to the console and file.
 * This version adds a new line at the end of the parameter string.
 * @param value to be printed.
 */
void FileOut::toPrintln(string value) {
    cout << value << endl;
    ofstream myfile;
    myfile.open( filename.c_str(), ios::out | ios::app );
    if (myfile.is_open()){
        myfile << value << endl;    // Prints a new line after the string.
        myfile.close();
    }
    else {cout << "UNABLE TO OPEN FILE " << filename << endl;}

}

/**
 * Print command that writes to the console and file.
 * This version doesn't add a new line at the end of the parameter string.
 * @param value to be printed.
 */
void FileOut::toPrint(string value) {
    cout << value;
    ofstream myfile;
    myfile.open( filename.c_str(), ios::out | ios::app );
    if (myfile.is_open()){
        myfile << value;        // Doesn't print a new line after the string.
        myfile.close();
    }
    else {cout << "UNABLE TO OPEN FILE " << filename << endl;}

}

/**
 * Write the input to the file but not the console.
 * This is used to store the name and description of the monk at the start of the file.
 * This is used to store a user's input in the textr file.
 * @param input string to be stored.
 */
void FileOut::storeInput(string input) {
    ofstream myfile;
    myfile.open( filename.c_str(), ios::out | ios::app );
    if (myfile.is_open()){
        myfile << input << endl;
        myfile.close();
    }
    else {cout << "UNABLE TO OPEN FILE " << filename << endl;}
}