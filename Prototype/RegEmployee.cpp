#include "Employee.cpp"

class RegEmployee : public EmployeePrototype {
public:
    RegEmployee() {
        EmpAddress = new Address();
    }

    ~RegEmployee() {
        delete EmpAddress;
    }

    EmployeePrototype* ShallowCopy() override {
        return new RegEmployee(*this);
    }

    EmployeePrototype* DeepCopy() override {
        RegEmployee* emp = new RegEmployee(*this);
        emp->EmpAddress = new Address{*EmpAddress}; // Deep copy the Address object
        return emp;
    }
};

