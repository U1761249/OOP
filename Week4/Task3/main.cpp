#pragma once
#include <iostream>
#include <time.h>
#include <string.h>
#include ".h files/Account.h"
#include ".h files/Person.h"

int main() {

    Person x = new Person("Adam");

    Account a;
    a.setAccountID("12345");
    a.setHolderName("Adam Birch");
    a.setBalance(154.26);

    double credit = 50;
    double debit = 75;
    double *creditPtr = &credit;
    double *debitPtr = &debit;


    std::cout << a.getAccountID() << "\n";
    std::cout << a.getHolderName() << "\n";
    std::cout << a.getBalance() << " Pounds \n";

    a.credit(creditPtr);
    std::cout << a.getBalance() << " Pounds \n";

    a.debit(debitPtr);
    std::cout << a.getBalance() << " Pounds \n";

    a.simulateInterest(4.5, 20);
}