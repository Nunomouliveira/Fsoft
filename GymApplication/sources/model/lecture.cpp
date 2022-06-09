//
// Created by migue on 09/06/2022.
//
#include "lecture.h"
#include "InvalidDataException.h"

Lecture::Lecture(Class* classes ){
    this->setClass(classes);
}
Lecture::Lecture(const Lecture& obj){
    this->setClass(obj.classes);
}
Lecture::~Lecture(){

}

Class* Lecture::getClass() const {
    return classes;
}

void Lecture::setClass(Class *classes) {

    if(classes!=NULL){
        this->classes = classes;
    }else{
        string msg = "Lecture: class = NULL";
        throw InvalidDataException(msg);
    }
}

bool Lecture::operator == (const Lecture& obj) const{
    if(*(this->classes) == *(obj.classes)){
        return true;
    }
    return false;
}
bool Lecture::operator == (const Class* ptr) const{
    if(*(this->classes) == *ptr){
        return true;
    }
    return false;
}


