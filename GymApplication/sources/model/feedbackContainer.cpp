//
// Created by migue on 10/06/2022.
//
#include "DuplicatedDataException.h"
#include "feedback.h"
#include "feedbackContainer.h"

using namespace std;

list<Feedback>::iterator FeedbackContainer::searchCla(int number, const string& initials, int feed){
    list<Feedback>::iterator it = this->feedbacks.begin();
    for (; it != this->feedbacks.end(); ++it){
        Class * classes = it->getClass();
        Client * client = it->getClient();
        Feed * feeds = it->getFeed();
        if(client->getNumber() == number && classes->getInitials() == initials && feeds->getFeed() == feed){
            return it;
        }
    }
    return it;
}
list<Feedback> FeedbackContainer::getAll(){
    list<Feedback> newlist (this->feedbacks);
    return newlist;
}
Feedback* FeedbackContainer::getCla(int number, const string& initials, int feed){
    list<Feedback>::iterator it = searchCla(number,initials,feed);
    if(it != this->feedbacks.end()){
        return &*it;
    }
    return NULL;
}

void  FeedbackContainer::add(const Feedback& obj){
    Class* classes = obj.getClass();
    Client * client = obj.getClient();
    Feed* feed = obj.getFeed();
    list<Feedback>::iterator it = searchCla(client->getNumber(),classes->getInitials(),feed->getFeed());
    if(it == this->feedbacks.end()){
        this->feedbacks.push_back(obj);
    }else{
        string msg = "Feedback Error";
        throw DuplicatedDataException(msg);
    }
}


