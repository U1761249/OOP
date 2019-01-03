#pragma once
#include <iostream>
#include <time.h>
#include <string.h>

//
// Created by ATBir on 13/10/2018.
//

#ifndef TASK2_ACCOUNT_H
#define TASK2_ACCOUNT_H


class Account {
public:

    Account();

    const std::string &getAccountID() const;

    void setAccountID(const std::string &accountID);

    const std::string &getHolderName() const;

    void setHolderName(const std::string &holderName);

    double getBalance() const;

    void setBalance(double balance);

    void credit(double value);

    void debit(double value);

    void simulateInterest(double rate, int years);

public:

private:
    std::string accountID; // string ID
    std::string holderName; // string Name
    double balance; // double Balance in Account
};

#endif //TASK2_ACCOUNT_H
