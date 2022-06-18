//
// Created by migue on 09/06/2022.
//
#include "DuplicatedDataException.h"
#include "enroll.h"
#include "enrollContainer.h"

using namespace std;

list<Enroll>::iterator EnrollContainer::search(int number, const string& initials){

    list<Enroll>::iterator it = this->enrolls.begin();
    for (; it != this->enrolls.end(); ++it){
        Class * classes = it->getClass();
        Client * client = it->getClient();
        if(client->getNumber()== number && classes->getInitials() == initials){
            return it;
        }
    }
    return it;
}
list<Enroll>  EnrollContainer::getAll(){
    list<Enroll> newlist (this->enrolls);
    return newlist;
}
Enroll*  EnrollContainer::get(int number, const string& initials){
    list<Enroll>::iterator it = search(number,initials);
    if(it != this->enrolls.end()){
        return &*it;
    }
    return NULL;
}

void  EnrollContainer::add(const Enroll& obj){
    Class* classes = obj.getClass();
    Client * client = obj.getClient();
    list<Enroll>::iterator it = search(client->getNumber(),classes->getInitials());
    if(it == this->enrolls.end()){
        this->enrolls.push_back(obj);
    }else{
        string msg = "Enroll: Error" ;
        throw DuplicatedDataException(msg);
    }
}
void  EnrollContainer::remove(int number, const string& initials){
    list<Enroll>::iterator it = search(number,initials);
    if(it != this->enrolls.end()){
        this->enrolls.erase(it);
    }
}




