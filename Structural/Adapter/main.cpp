#include <iostream>
#include <string>
//#include "C:\Users\Data-DCS\Design-Patterns\Adapter\Employee_class.cpp"
// #include "MachineOperator_class.cpp"
//#include "SalaryCalculator_class.cpp"
#include "SalaryAdapter_class.cpp"
using namespace std;

int main() {
    // create object of SalaryCalculator class
    Employee emp;
    emp.name = "Hend";
    emp.basicSalary = 6000;

    // If I have another system returns MachineOperator type not Employee type and I want to calculate his salary;
    // In this case I will need an adapter to convert the return type of the other system which is MachineOperator to the input type of my function which is Employee type
    MachineOperator machineOperator;
    machineOperator.basicSalary = 1000;

    // calling adapter class
    SalaryAdapter calc;

    SalaryCalculator sc;
    int salary = sc.calcSalary(emp);
    // I can't write int salary = sc.calcSalary(machineOperator);
    // As this function expects Employee object not MachineOperator object
    // In this case, I have two solutions:
    // The first one is to convert the machineOperator object into emp object; to be able to call calcSalary method
    // The second one is to make salary adapter/salaryCalculator adapter; which gets machineOperator and internally convert it to emp object and calculates salary;
    int salary_adapter = calc.calcSalary(machineOperator);
    cout << salary << endl; 
    cout << salary_adapter << endl;
}