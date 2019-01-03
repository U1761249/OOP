//
// Created by ATBir on 09/11/2018.
//
#include <iostream>
#ifndef TASK2_ACCOUNT_H
#define TASK2_ACCOUNT_H

using namespace std;

class Account {
public:


public:
    virtual double getBalance() const = 0;
    const void printDetails();
private:
    string fName;
    string lName;
    string nin;
    double balance ;

};


#endif //TASK2_ACCOUNT_H
