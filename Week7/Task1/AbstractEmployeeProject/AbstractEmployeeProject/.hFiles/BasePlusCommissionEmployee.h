#pragma once
#include "CommissionEmployee.h" // CommissionEmployee class definition

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(const string &, const string &,
		const string &, int, int, int, double = 0.0, double = 0.0,
		double = 0.0);

	void setBaseSalary(double); // set base salary
	double getBaseSalary() const; // return base salary

	// keyword virtual signals intent to override
	virtual double earnings() const; // calculate earnings
	virtual void print() const; // print BasePlusCommissionEmployee object
private:
	double baseSalary; // base salary per week
}; // end class BasePlusCommissionEmployee