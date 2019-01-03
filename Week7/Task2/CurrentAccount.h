//
// Created by ATBir on 09/11/2018.
//

#ifndef TASK2_CURRENTACCOUNT_H
#define TASK2_CURRENTACCOUNT_H
#include <iostream>;
#include ".hFiles/Account.h"

using namespace std;

class CurrentAccount : Account{
    CurrentAccount(const string &fName, const string &lName, const string &nin);

    CurrentAccount(const string &fName, const string &lName, const string &nin, double balance);
};


#endif //TASK2_CURRENTACCOUNT_H
