//
// Created by migue on 09/06/2022.
//
#include "gym.h"

Gym::Gym(){
    this->name = "";
    setDataForConsistency();

}
Gym::Gym(const string& name){
    this->name = name;
    setDataForConsistency();
}
Gym::Gym(const Gym& obj){
    this->name = obj.name;
    this->feed = obj.feed;
    this->feedback=obj.feedback;
    this->classes = obj.classes;
    this->clients = obj.clients;
    this->employees = obj.employees;
    this->enrolls = obj.enrolls;
    setDataForConsistency();
}

const string& Gym::getName() const {
    return name;
}

void Gym::setName(const string &name) {
    this->name = name;
}

ClassContainer & Gym::getClassContainer(){
    return this->classes;
}
ClientContainer & Gym::getClientContainer() {
    return this->clients;
}
EmployeeContainer & Gym::getEmployeeContainer() {
    return this->employees;
}
EnrollContainer & Gym::getEnrollContainer(){
    return this->enrolls;
}
FeedbackContainer & Gym::getFeedbackContainer() {
    return this->feedback;
}
FeedContainer & Gym::getFeedContainer() {
    return this->feed;
}

void Gym::setDataForConsistency(){
    this->clients.setEnrolls(&this->enrolls);
    this->clients.setFeeds(&this->feed);
    this->classes.setEnrolls(&this->enrolls);
    this->classes.setEmployees(&this->employees);
    this->classes.setFeeds(&this->feed);
}





