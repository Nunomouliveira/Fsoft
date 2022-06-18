//
// Created by migue on 09/06/2022.
//
#include <iostream>
#include "employee.h"
#include "InvalidDataException.h"


Employee::Employee(const string &initials, const string &name) :Person(name){
    setInitials(initials);
}

Employee::Employee(const Employee &obj) : Person(obj.name){
    setInitials(obj.initials);
    this->lectures = obj.lectures;
}

Employee::~Employee(){

}

const string& Employee::getInitials() const {
    return initials;
}

void Employee::setInitials(const string &initials) {
    this->initials = initials;
}
LectureContainer & Employee::getLectures(){
    return this->lectures;
}

bool Employee::operator == (const Employee& obj) const{
    if(this->initials == obj.initials){
        return true;
    }
    return false;
}

bool Employee::operator == (const string initials) const{
    if(this->initials == initials){
        return true;
    }
    return false;
}





