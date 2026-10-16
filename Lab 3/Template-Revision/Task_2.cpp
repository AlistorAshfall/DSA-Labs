#include "Employee.h"

int main() 
{
    FullTimeEmployee emp1(50000);
    PartTimeEmployee emp2(80, 500);

    cout << "Full Time Employee Salary: "
        << emp1.calculateSalary() << endl;

    cout << "Part Time Employee Salary: "
        << emp2.calculateSalary() << endl;

    return 0;
}