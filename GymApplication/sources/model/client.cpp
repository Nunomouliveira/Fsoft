//
// Created by migue on 09/06/2022.
//
#include "client.h"

int Client::NUMBER = 0;

Client::Client(const string &name, const string &age) :Person(name){
    this->number = ++NUMBER;
    this->age = age;
}



Client::Client(const Client& client): Person(client.name){
    this->number = client.number;
    this->age = client.age;
}
Client::~Client(){
}



int Client::getNumber() const {
    return number;
}

void Client::setNumber(int number) {
    this->number = number;
}
void Client::setAge(string age) {
    this->age = age;
}
string Client::getAge() const {
    return age;
}
bool Client::operator == (const Client& obj) const{
    if(this->number == obj.number){
        return true;
    }
    return false;
}


bool Client::operator == (int nr) const{
    if(this->number == nr){
        return true;
    }
    return false;
}

bool Client::operator == (const string name){
    if(this->name == name){
        return true;
    }
    return false;
}
bool Client::ValidAge(const string &age) {
    if(age.length()<=0){
        return false;
    }
    return true;
}