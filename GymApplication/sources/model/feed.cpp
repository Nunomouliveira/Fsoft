//
// Created by migue on 10/06/2022.
//
#include "feed.h"
#include "InvalidDataException.h"

bool Feed::ValidFeed(const int feed) {
    if(feed < 0 || feed > 5){
        return false;
    }
    return true;
}
Feed::Feed(int feed){
    setFeed(feed);
}

Feed::Feed(const Feed& obj){
    setFeed(obj.feed);
}

Feed::~Feed() {
}
const int Feed::getFeed() const {
    return feed;
}

void Feed::setFeed(const int feed) {
    if (ValidFeed(feed)== true) {
        this->feed = feed;
    }else{
        string msg = "Feed: " + feed;
        throw InvalidDataException(msg);
    }
}


bool Feed::operator == (const Feed& obj) const{
    if(this->feed == obj.feed){
        return true;
    }
    return false;
}
bool Feed::operator == (const int nr) const{
    if(this->feed == feed){
        return true;
    }
    return false;
}


