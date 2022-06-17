//
// Created by migue on 09/06/2022.
//
#include "client.h"
#include <iostream>
#include "InvalidDataException.h"
int Client::NUMBER = 0;

Client::Client(const string &name, int age) :Person(name){
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
void Client::setAge(int age) {
    if (ValidAge(age)== true) {
        this->age = age;
    }else{
        string msg = "Age error";
        throw InvalidDataException(msg);
    }
}
int Client::getAge() const {
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

bool Client::ValidAge(int age) {
    if(age<15){
        return false;
    }
    return true;
}