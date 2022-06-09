//
// Created by migue on 09/06/2022.
//
#include "enroll.h"
#include "InvalidDataException.h"

bool Enroll::pointer(void * ptr){
    if(ptr == NULL){
        return false;
    }
    return true;
}


Enroll::Enroll(Class * classes, Client * client){
    this->setClass(classes);
    this->setClient(client);
}

Enroll::Enroll(const Enroll& obj){
    this->setClass(obj.classes);
    this->setClient(obj.client);
}
Enroll::~Enroll(){

}

Class* Enroll::getClass() const {
    return classes;
}

void Enroll::setClass(Class *classes) {
    if(pointer(classes)==true){
        this->classes = classes;
    }else{
        string msg = "Enroll: class = NULL";
        throw InvalidDataException(msg);
    }
}

Client* Enroll::getClient() const{
    return this->client;
}
void Enroll::setClient(Client *client){

    if(pointer(client)==true){
        this->client = client;
    }else{
        string msg = "Enroll: client = NULL";
        throw InvalidDataException(msg);
    }

}

bool Enroll::operator == (const Enroll& obj) const{
    if((*(this->classes) == *(obj.classes)) && (*(this->client) == *(obj.client))){
        return true;
    }
    return false;
}




