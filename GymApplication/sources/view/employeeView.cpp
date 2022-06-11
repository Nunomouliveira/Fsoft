//
// Created by nunon on 09/06/2022.
//

#include <iostream>
#include "employeeView.h"
#include "utils.h"
#include "InvalidDataException.h"
using namespace std;


Employee EmployeeView::getEmployee() {
    Employee employee("Initials", "Name");
    string name;
    string initials;
    bool flag = false;
    do{
        try{
            flag = false;
            cout << "Enter Employee Name: ";
            cin >> name;
            cout << "Enter Employee Initials";
            cin >> initials;
            employee.setName(name);
            employee.setInitials(initials);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return employee;
}

void EmployeeView::printEmployee(Employee *employee) {
    cout<<employee->getName()<<" - "<<employee->getInitials()<<endl;

}
void EmployeeView::printEmployees(list<Employee> &employees) {
    for (list<Employee>::iterator it=employees.begin(); it != employees.end(); ++it){
        printEmployee(&*it);
    }
}
