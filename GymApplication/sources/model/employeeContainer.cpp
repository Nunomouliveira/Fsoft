//
// Created by migue on 09/06/2022.
//

#include "DuplicatedDataException.h"
#include "employeeContainer.h"


list<Employee>::iterator EmployeeContainer::search(const string& initials){
    list<Employee>::iterator it = employees.begin();
    for (; it != employees.end(); ++it){
        if((*it) == initials){
            return it;
        }
    }
    return it;
}
list<Employee>  EmployeeContainer::getAll(){
    list<Employee> newlist (employees);
    return newlist;
}
Employee* EmployeeContainer::get(const string& initials){
    list<Employee>::iterator it = search(initials);
    if(it != employees.end()){
        return &(*it);
    }
    return NULL;
}
void  EmployeeContainer::add(const Employee& obj){
    list<Employee>::iterator it = search(obj.getInitials());
    if(it == employees.end()){
        employees.push_back(obj);
    }else{
        string msg = "Employee: Error";
        throw DuplicatedDataException(msg);
    }

}
void  EmployeeContainer::remove(const string& initials){
    list<Employee>::iterator it = search(initials);
    if(it != employees.end()){
        employees.erase(it);
    }
}

