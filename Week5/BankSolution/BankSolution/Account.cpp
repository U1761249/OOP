#include "stdafx.h"
#include "Account.h"



using namespace std;
accountCount = 0;

//Constructor which takes an account number and a double balance
Account::Account(int * accNo, double  * bal)
{
	accountCount++;
	this->balance = *bal;
	this->accountNo = *accNo;
}

//Credit method to add an amount to the current balance
bool Account::credit(double * in)
{
	if (in > 0)
	{
		this->balance += *in;
		return true;
	}

	return false;

}

//Debit method to remove an amount from the balance
bool Account::debit(double * in)
{
	if (in > 0)
	{
		this->balance += *in;
		return true;
	}
	return false;
}

//Returns a string that contains the Account number and balance
string Account::getDetails() const
{
	ostringstream conAcc, conBal;
	conAcc << this->accountNo;
	string toRet;
	toRet += "Account No: ";
	toRet += conAcc.str();
	toRet += " Balance : ";
	conBal << this->balance;
	toRet += conBal.str();
	return toRet;
}

//Return the account number
int Account::getAccNo()
{
	return accountNo;
}

//Deconstructor
Account::~Account() {
	// TODO Auto-generated destructor stub
}