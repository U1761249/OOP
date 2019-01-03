#pragma once
#include "stdafx.h"

using namespace std;

ref class Account{
public:
	Account();
	virtual ~Account();
	bool debit(double *);
	bool credit(double *);
	int getAccNo();
	void setDetails(int *, double *);
	double getBalance();
	string getDetails() ;
private:
	double balance;
	int accountNo;
};

