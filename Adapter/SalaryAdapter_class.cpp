#include <iostream>
//#include "Employee_class.cpp"
#include "SalaryCalculator_class.cpp"
#include "MachineOperator_class.cpp"

// it should have access to calcSalary function of emp object, so I will inherent SalaryCalculator class to be able to access its function.
class SalaryAdapter : public SalaryCalculator {
private:
    Employee _emp;

public:
    double calcSalary (MachineOperator _operator) {
        _emp.basicSalary = _operator.basicSalary;
        return SalaryCalculator::calcSalary(_emp);
    } 
};