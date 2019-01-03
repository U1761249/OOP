#pragma once
#include "stdafx.h"

using namespace std;

class Account {
public:
	Account(int *, double *);
	virtual ~Account();
	bool debit(double *);
	bool credit(double *);
	int getAccNo();
	string getDetails() const;
private:
	double balance;
	int accountNo;
	static int accountCount;
};

