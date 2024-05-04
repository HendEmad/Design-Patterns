#include "TempEmployee.cpp"

int main() {
    TempEmployee employee;
    employee.Id = 1;
    employee.Name = "John Doe";
    employee.EmpAddress->City = "nCity";
    employee.EmpAddress->StreetName = "Street";
    employee.EmpAddress->Building = "Building";

    EmployeePrototype* shallowCopy = employee.ShallowCopy();
    EmployeePrototype* deepCopy = employee.DeepCopy();

    // Modify the original employee's address
    employee.EmpAddress->City = "New City";
    employee.EmpAddress->StreetName = "New Street";
    employee.EmpAddress->Building = "New Building";

    std::cout << "Original:\n" << employee.ToString() << std::endl;
    std::cout << "Shallow Copy:\n" << shallowCopy->ToString() << std::endl;
    std::cout << "Deep Copy:\n" << deepCopy->ToString() << std::endl;

    delete shallowCopy;
    delete deepCopy;

    return 0;
}
