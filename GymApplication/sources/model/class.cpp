//
// Created by migue on 09/06/2022.
//
#include "class.h"
#include "InvalidDataException.h"

bool Class::ValidInitials(const string &initials) {
    if(initials.length() < 4){
        return false;
    }
    return true;
}
Class::Class(string initials, string denomination){
    setInitials(initials);
    this->denomination = denomination;
}

Class::Class(const Class& obj){
    setInitials(obj.initials);
    this->denomination = obj.denomination;
}

Class::~Class() {
}
const string& Class::getDenomination() const {
    return denomination;
}

void Class::setDenomination(const string &denomination) {
    this->denomination = denomination;
}

const string& Class::getInitials() const {
    return initials;
}

void Class::setInitials(const string &initials) {
    if(ValidInitials(initials)){
        this->initials = initials;
    }else{

        string msg = "Employee: " + initials;
        throw InvalidDataException(msg);
    }
}

bool Class::operator == (const Class& obj) const{
    if(this->initials == obj.initials){
        return true;
    }
    return false;
}
bool Class::operator == (const string& str) const{
    if(this->initials == str){
        return true;
    }
    return false;
}

