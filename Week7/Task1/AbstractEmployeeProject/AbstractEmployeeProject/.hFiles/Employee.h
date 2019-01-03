#pragma once
#include "stdafx.h"
#include "Date.h"
using namespace std;

class Employee
{
public:
	Employee(const string &, const string &, const string &,
		int, int, int);

	void setFirstName(const string &); // set first name
	string getFirstName() const; // return first name

	void setLastName(const string &); // set last name
	string getLastName() const; // return last name

	void setNINumber(const string &); // set SSN
	string getNINumber() const; // return SSN

	void setBirthDate(int, int, int); // set birthday
	Date getBirthDate() const; // return birthday

	// pure virtual function makes Employee abstract base class
	virtual double earnings() const = 0; // pure virtual
	virtual void print() const; // virtual
private:
	string firstName;
	string lastName;
	string niNumber;
	Date birthDate; // the Employee's birthday
}; // end class Employee
