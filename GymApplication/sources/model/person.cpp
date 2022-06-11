//
// Created by migue on 09/06/2022.
//
#include "person.h"
#include "InvalidDataException.h"



bool Person::ValidName(const string &name) {
    if(name.length() < 1){
        return false;
    }
    return true;
}

Person::Person(const string& name){
    setName(name);
}
Person::Person(const Person& person){
    setName(person.name);
}

Person::~Person(){
}

const string&  Person::getName() const {
    return name;
}
void Person::setName(const string &name) {
    if(ValidName(name)){
        this->name = name;
    }else{
        string msg = "Person: " + name;
        throw InvalidDataException(msg);
    }
}


