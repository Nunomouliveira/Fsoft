//
// Created by migue on 09/06/2022.
//
#include "DuplicatedDataException.h"
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
        string msg = "Client error";
        throw DuplicatedDataException(msg);
    }
}
void  ClientContainer::remove(int number){
    list<Client>::iterator it = search(number);
    if(it != this->clients.end()){
        this->clients.erase(it);
    }
}
void ClientContainer::setEnrolls(EnrollContainer *enrolls) {
    this->enrolls = enrolls;
}
void ClientContainer::setFeeds(FeedbackContainer *feeds) {
    this->feeds = feeds;
}




