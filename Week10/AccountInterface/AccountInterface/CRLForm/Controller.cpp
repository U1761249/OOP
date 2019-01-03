#include "Controller.h"
#include "Account.h"

Controller::Controller()
{
}

bool Controller::setup(int n, double bal)
{
	acc1.setDetails(&n, &bal);
	return true;
}

double Controller::getBalance()
{
	return acc1.getBalance();
}

bool Controller::credit(double in)
{
	return acc1.credit(&in);
}

bool Controller::debit(double out)
{
	return acc1.debit(&out);;
}
