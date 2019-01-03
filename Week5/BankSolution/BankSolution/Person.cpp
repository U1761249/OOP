#include "stdafx.h"
#include "Person.h"


using namespace std;

//Constructor that takes a String name
Person::Person(string n)
	:name(n)
{

}

//addAccount method adds an Account object to the accounts Vector
void Person::addAccount(Account &acc)
{
	accounts.push_back(acc);
}

//closeAccount method removes and Account object based on the specified Account Number.
bool Person::closeAccount(int * accNo)
{
	for (int i = 0; i<accounts.size(); i++)
	{
		if (accounts.at(i).getAccNo() == *accNo)
		{
			accounts.erase(accounts.begin() + i);
			return true;
		}
		//
	}
	return false;
}

//debitMoney method adds an amount to an Account specified by the accNo.
//Returns true is the debit was successful, and false if either the account
//was not found or the amount was negative.
bool Person::debitMoney(int * accNo, double * ammount)
{
	for (int i = 0; i<accounts.size(); i++)
	{
		if (accounts.at(i).getAccNo() == *accNo)
		{
			return accounts.at(i).debit(ammount);
		}
	}
	return false;
}

//creditMoney method removes an amount to an Account specified by the accNo.
//Returns true is the credit was successful, and false if either the account
//was not found or the amount was negative.
bool Person::creditMoney(int * accNo, double * bal)
{
	for (int i = 0; i<accounts.size(); i++)
	{
		if (accounts.at(i).getAccNo() == *accNo)
		{
			return accounts.at(i).credit(bal);
		}
	}
	return false;
}

//printAllAccounts prints the information out for each of the account objects.
void Person::printAllAccounts()
{
	if (accounts.size() > 0){
		for (int i = 0; i<accounts.size(); i++)
		{
			cout << accounts.at(i).getDetails().c_str() << endl;
		}
	}
	else{
		cout << "Person : " << name << " has no accounts" << endl;
	}

}

//Deconstructor clears the Accounts.
Person::~Person()
{
	accounts.clear();
}
