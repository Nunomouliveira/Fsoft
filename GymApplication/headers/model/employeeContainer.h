//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_EMPLOYEECONTAINER_H
#define GYMAPPLICATION_EMPLOYEECONTAINER_H
#include <list>
#include "employee.h"

class EmployeeContainer{
private:
    list<Employee> employees;
public:
    list<Employee>::iterator search(const string& initials);
    list<Employee> getAll();
    Employee* get(const string& initials);
    void add(const Employee& obj);
    void remove(const string& initials);
};

#endif //GYMAPPLICATION_EMPLOYEECONTAINER_H
