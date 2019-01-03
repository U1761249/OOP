#include "../.hFiles/stdafx.h"
// BasePlusCommissionEmployee class definition
#include "../.hFiles/BasePlusCommissionEmployee.h"
using namespace std;

// constructor 
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	const string &first, const string &last, const string &ssn,
	int month, int day, int year, double sales,
	double rate, double salary)
	: CommissionEmployee(first, last, ssn, month, day, year, sales, rate)
{
	setBaseSalary(salary); // validate and store base salary
} // end BasePlusCommissionEmployee constructor

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	baseSalary = ((salary < 0.0) ? 0.0 : salary);
} // end function setBaseSalary

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary;
} // end function getBaseSalary

// calculate earnings;
// override pure virtual function earnings in Employee
double BasePlusCommissionEmployee::earnings() const
{
	return getBaseSalary() + CommissionEmployee::earnings();
} // end function earnings

// print BasePlusCommissionEmployee's information 
void BasePlusCommissionEmployee::print() const
{
	cout << "base-salaried ";
	CommissionEmployee::print(); // code reuse
	cout << "; base salary: " << getBaseSalary();
} // end function print