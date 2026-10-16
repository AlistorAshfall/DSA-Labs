#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee 
{
public:

	virtual double calculateSalary() = 0;
	virtual ~Employee() {};

};

class FullTimeEmployee : public Employee 
{
private:
	double salary;
public:
	FullTimeEmployee(double s) : salary(s) {};

	double calculateSalary() override { return salary; };

};

class PartTimeEmployee : public Employee
{
private:
	double hoursworked;
	double rateperhrs;
public:

	PartTimeEmployee(double h, double r) : hoursworked(h), rateperhrs(r) {};

	double calculateSalary() override { return hoursworked * rateperhrs; };

};
#endif