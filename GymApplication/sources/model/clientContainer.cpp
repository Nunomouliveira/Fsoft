//
// Created by migue on 09/06/2022.
//
#include <tuple>
#include "DuplicatedDataException.h"
#include "DataConsistencyException.h"
#include "clientContainer.h"
using namespace std;

list<Client>::iterator ClientContainer::search(int number){
    list<Client>::iterator it = this->clients.begin();
    for (; it != this->clients.end(); ++it){
        if((*it) == number){
            return it;
        }
    }
    return it;
}
list<Client> ClientContainer::getAll(){
    list<Client> newlist (this->clients);
    return newlist;
}
Client* ClientContainer::get(int number){
    list<Client>::iterator it = search(number);
    if(it != this->clients.end()){
        return &(*it);
    }
    return NULL;

}
void ClientContainer::add(const Client& obj){
    list<Client>::iterator it = search(obj.getNumber());
    if(it == this->clients.end()){
        this->clients.push_back(obj);
    }else{
        string msg = "Clinet: " + to_string(obj.getNumber());
        throw DuplicatedDataException(msg);
    }
}
void ClientContainer::remove(int number){
    list<tuple<Client *, int>> l;
    list<Client>::iterator it = search(number);
    if(it != this->clients.end()){
        l = this->enrolls->getClasses(number);
        if(l.size() == 0){
            this->clients.erase(it);
        }else{
            string msg = "Client: " + to_string(number);
            throw DataConsistencyException(msg);

        }
    }
}
void ClientContainer::setEnrolls(EnrollContainer *enrolls) {
    this->enrolls = enrolls;
}




