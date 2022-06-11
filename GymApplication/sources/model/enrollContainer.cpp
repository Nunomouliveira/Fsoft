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
list<tuple<Class *, int>> EnrollContainer::getClasses(int number) {
    list<tuple<Class *, int>> newlist;
    for (list<Enroll>::iterator it = this->enrolls.begin(); it != this->enrolls.end(); ++it){
        Client * client = it->getClient();
        if(client->getNumber()== number){
            tuple<Class *, int> t = make_tuple(it->getClass(),0);
            newlist.push_back(t);
        }
    }
    return newlist;
}
list<Client *> EnrollContainer::getClients(const string &initials) {
    list<Client *> newlist;
    for (list<Enroll>::iterator it = this->enrolls.begin(); it != this->enrolls.end(); ++it){
        Class * classes = it->getClass();
        if(classes->getInitials() == initials){
            newlist.push_back(it->getClient());
        }
    }
    return newlist;
}

void  EnrollContainer::add(const Enroll& obj){
    Class* classes = obj.getClass();
    Client * client = obj.getClient();
    list<Enroll>::iterator it = search(client->getNumber(),classes->getInitials());
    if(it == this->enrolls.end()){
        this->enrolls.push_back(obj);
    }else{
        string msg = "Enroll: " + to_string(client->getNumber())+" " + classes->getInitials();
        throw DuplicatedDataException(msg);
    }
}
void  EnrollContainer::remove(int number, const string& initials){
    list<Enroll>::iterator it = search(number,initials);
    if(it != this->enrolls.end()){
        this->enrolls.erase(it);
    }
}




