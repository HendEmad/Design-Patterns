#include <iostream>
#include <string>

class Address {
public:
    std::string City;
    std::string StreetName;
    std::string Building;
};

class EmployeePrototype {
public:
    int Id;
    std::string Name;
    Address* EmpAddress;

    virtual ~EmployeePrototype() {} // Virtual destructor

    virtual EmployeePrototype* ShallowCopy() = 0;
    virtual EmployeePrototype* DeepCopy() = 0;

    virtual std::string ToString() {
        return "Id: " + std::to_string(Id) + "\n"
             + "Name: " + Name + "\n"
             + "Address: " + EmpAddress->City + ", " + EmpAddress->StreetName + ", " + EmpAddress->Building + "\n";
    }
};