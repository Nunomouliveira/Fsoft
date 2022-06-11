//
// Created by nunon on 09/06/2022.
//

#ifndef FSOFT2022_1A_4_EMPLOYEEVIEW_H
#define FSOFT2022_1A_4_EMPLOYEEVIEW_H

#include <list>
#include "employee.h"
class EmployeeView {
public:
    Employee getEmployee();

    void printEmployee(Employee *employee);

    void printEmployees(list <Employee> &employees);
};
#endif //FSOFT2022_1A_4_EMPLOYEEVIEW_H
