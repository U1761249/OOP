#pragma once
#include <iostream>
#include <time.h>
#include <string.h>
#include ".h files/Account.h"

int main() {
    Account a;
    a.setAccountID("12345");
    a.setHolderName("Adam Birch");
    a.setBalance(154.26);

    std::cout << a.getAccountID() << "\n";
    std::cout << a.getHolderName() << "\n";
    std::cout << a.getBalance() << " Pounds \n";

    a.credit(50);
    std::cout << a.getBalance() << " Pounds \n";

    a.debit(75);
    std::cout << a.getBalance() << " Pounds \n";

    a.simulateInterest(4.5, 20);
}