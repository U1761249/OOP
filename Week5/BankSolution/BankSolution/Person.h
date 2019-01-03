#pragma once
#include "stdafx.h"
#include "Account.h"


using namespace std;

class Person {
public:
	Person(string);
	void addAccount(Account &);
	bool closeAccount(int *);
	void printAllAccounts();
	bool creditMoney(int *, double *);
	bool debitMoney(int *, double *);
	virtual ~Person();
private:
	const string name;
	vector<Account> accounts;
};


