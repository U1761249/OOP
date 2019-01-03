#pragma once
#include <iostream>
#include <time.h>
#include <string.h>

//
// Created by ATBir on 19/10/2018.
//

#ifndef TASK3_ACCOUNT_H
#define TASK3_ACCOUNT_H


class Account {
public:

    Account();

    Account(const std::string &accountID, const std::string &holderName);

    const std::string &getAccountID() const;

    void setAccountID(const std::string &accountID);

    const std::string &getHolderName() const;

    void setHolderName(const std::string &holderName);

    double getBalance() const;

    void setBalance(double balance);

    void credit(double *valuePtr);

    void debit(double *valuePtr);

    void simulateInterest(double rate, int years);

public:

private:
    std::string accountID; // string ID
    std::string holderName; // string Name
    double balance; // double Balance in Account
};

#endif //TASK3_ACCOUNT_H
