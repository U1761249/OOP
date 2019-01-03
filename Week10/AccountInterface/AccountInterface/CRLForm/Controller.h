#pragma once
#include "Account.h"

using namespace std;

ref class Controller
{
public:
	Controller();
	bool setup(int n, double bal);
	double getBalance();
	bool credit(double a);
	bool debit(double a);
public:
	Account acc1;
};
