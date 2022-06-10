//
// Created by migue on 10/06/2022.
//
#include "DuplicatedDataException.h"
#include "FeedContainer.h"
#include "DataConsistencyException.h"

list<Feed>::iterator FeedContainer::search(int feed) {
    list<Feed>::iterator it = this->feeds.begin();
    for (; it != this->feeds.end(); ++it){
        if((*it) == feed){
            return it;
        }
    }
    return it;
}
list<Feed> FeedContainer::getAll(){
    list<Feed> newlist (this->feeds);
    return newlist;
}
Feed* FeedContainer::get(int feed){
    list<Feed>::iterator it = search(feed);
    if(it != this->feeds.end()){
        return &(*it);
    }
    return NULL;

}
void FeedContainer::add(const Feed& obj){
    list<Feed>::iterator it = search(obj.getFeed());
    if(it == this->feeds.end()) {
        this->feeds.push_back(obj);
        string msg = "Feedback: ";
    }
}

void FeedContainer::setFeedback(FeedbackContainer *feedbacks) {
    this->feedbacks = feedbacks;
}
