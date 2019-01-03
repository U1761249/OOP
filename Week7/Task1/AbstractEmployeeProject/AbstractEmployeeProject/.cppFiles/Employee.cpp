#include "../.hFiles/stdafx.h"
#include "../.hFiles/Employee.h"


using namespace std;

// constructor
Employee::Employee(const string &first, const string &last,
	const string &ssn, int month, int day, int year)
	: firstName(first), lastName(last), niNumber(ssn),
	birthDate(month, day, year)
{
	// empty body 
} // end Employee constructor

// set first name
void Employee::setFirstName(const string &first)
{
	firstName = first;
} // end function setFirstName

// return first name
string Employee::getFirstName() const
{
	return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName(const string &last)
{
	lastName = last;
} // end function setLastName

// return last name
string Employee::getLastName() const
{
	return lastName;
} // end function getLastName

// set social security number
void Employee::setNINumber(const string &ssn)
{
	niNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
string Employee::getNINumber() const
{
	return niNumber;
} // end function getSocialSecurityNumber

// set birthday
void Employee::setBirthDate(int month, int day, int year)
{
	birthDate.setDate(month, day, year);
} // end function setBirthDate

// return birthday
Date Employee::getBirthDate() const
{
	return birthDate;
} // end function getBirthDate

// print Employee's information (virtual, but not pure virtual)
void Employee::print() const
{
	cout << getFirstName() << ' ' << getLastName()
		<< "\nbirthday: " << getBirthDate()
		<< "\nNational Insurance: " << getNINumber();
} // end function print
