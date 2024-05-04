#include "Employee.cpp"

class TempEmployee : public EmployeePrototype {
public:
    TempEmployee() {
        EmpAddress = new Address();
    }

    ~TempEmployee() {
        delete EmpAddress;
    }

    EmployeePrototype* ShallowCopy() override {
        return new TempEmployee(*this);
    }

    EmployeePrototype* DeepCopy() override {
        TempEmployee* emp = new TempEmployee(*this);
        emp->EmpAddress = new Address{*EmpAddress}; // Deep copy the Address object
        return emp;
    }
};

