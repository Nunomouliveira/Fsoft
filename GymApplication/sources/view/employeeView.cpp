//
// Created by nunon on 09/06/2022.
//

#include <iostream>
#include "employeeView.h"
#include "Utils.h"
#include "InvalidDataException.h"
using namespace std;


employee EmployeeView::getEmployee() {
    employee employee("Initials", "Name");
    bool flag = false;
    do{
        try{
            flag = false;
            cout<<"Employee"<<endl;
            string name = Utils::getString("Name");
            string initials = Utils::getString("Initials");
            employee.setName(name);
            employee.setInitials(initials);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return employee;
}

void EmployeeView::printEmployee(employee *employee) {
    cout<<employee->getInitials()<<":"<<employee->getName()<<endl;

}
void EmployeeView::printEmployees(list<employee> &employees) {
    for (list<employee>::iterator it=employees.begin(); it != employees.end(); ++it){
        printEmployee(&*it);
    }
}
