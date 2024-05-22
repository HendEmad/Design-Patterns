#include <iostream>
#include "Employee_class.cpp"
using namespace std;

class SalaryCalculator {
public:
    double calcSalary(Employee emp) {
        return emp.basicSalary * 1.5;
    }
};