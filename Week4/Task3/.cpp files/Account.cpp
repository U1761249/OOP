//
// Created by ATBir on 13/10/2018.
//

#include <cmath>
#include "../.h files/Account.h"

Account::Account() {
    accountID = " ";
    holderName = " ";
    balance = 0;
}


const std::string &Account::getAccountID() const {
    return accountID;
}

void Account::setAccountID(const std::string &accountID) {
    Account::accountID = accountID;
}

const std::string &Account::getHolderName() const {
    return holderName;
}

void Account::setHolderName(const std::string &holderName) {
    Account::holderName = holderName;
}

double Account::getBalance() const {
    return balance;
}

void Account::setBalance(double balance) {
    Account::balance = balance;
}

void Account::credit(double *valuePtr) {
    double value = *valuePtr;
    balance = balance + value;
}

void Account::debit(double *valuePtr) {
    double value = *valuePtr;
    balance = balance - value;

}

void Account::simulateInterest(double rate, int years) {
    double simBalance = balance;
    std::cout << balance << " pounds up for interest \n";
    for (int i = 0; i < years; i++){
        simBalance = (((simBalance/100)*rate) + simBalance);
        std::cout << simBalance << " Pounds at year " << i+1 << "\n";
    }
}


