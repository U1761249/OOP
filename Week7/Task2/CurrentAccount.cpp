//
// Created by ATBir on 09/11/2018.
//

#include "CurrentAccount.h"
using namespace std;

CurrentAccount::CurrentAccount(const string &fName, const string &lName, const string &nin) : fName(fName), lName(lName), nin(nin) {balance = (double)0;}

CurrentAccount::CurrentAccount(const string &fName, const string &lName, const string &nin, double balance) : fName(fName), lName(lName), nin(nin), balance(balance) {}