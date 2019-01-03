#include <iostream>
#include <vector>
#include "Account.h"

//
// Created by ATBir on 19/10/2018.
//

#ifndef TASK3_PERSON_H
#define TASK3_PERSON_H


class Person {
public:
    Person(const std::vector<Account> &v);

    Person(const std::vector<Account> &v, const std::string &name);

    Person(const std::string &name);

    void openAccount();
    void closeAccount();
    std::string getName() ;


private:
    std::vector<Account> v;
    std::string name;
};


#endif //TASK3_PERSON_H
