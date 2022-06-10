//
// Created by migue on 10/06/2022.
//
#include "feedback.h"
#include "InvalidDataException.h"

bool Feedback::pointer(void * ptr){
    if(ptr == NULL){
        return false;
    }
    return true;
}


Feedback::Feedback(Class *classes, Client *client, Feed *feed) {
    this->setClass(classes);
    this->setClient(client);
    this->setFeed(feed);
}

Feedback::Feedback(const Feedback &obj) {
    this->setClass(obj.classes);
    this->setClient(obj.client);
    this->setFeed(obj.feed);
}


Class* Feedback::getClass() const {
    return classes;
}

void Feedback::setClass(Class *classes) {
    if(pointer(classes)==true){
        this->classes = classes;
    }else{
        string msg = "Feedback: class = NULL";
        throw InvalidDataException(msg);
    }
}

Client* Feedback::getClient() const{
    return this->client;
}
void Feedback::setClient(Client *client){

    if(pointer(client)==true){
        this->client = client;
    }else{
        string msg = "Enroll: client = NULL";
        throw InvalidDataException(msg);
    }

}

bool Feedback::operator == (const Feedback& obj) const{
    if((*(this->classes) == *(obj.classes)) && (*(this->client) == *(obj.client))){
        return true;
    }
    return false;
}



Feedback::~Feedback() {

}

void Feedback::setFeed(Feed *feed) {
    if(pointer(feed)==true){
        this->feed = feed;
    }else{
        string msg = "Feedback: class = NULL";
        throw InvalidDataException(msg);
    }
}

Feed *Feedback::getFeed() const {
    return this->feed;
}




