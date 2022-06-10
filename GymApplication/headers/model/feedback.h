//
// Created by migue on 10/06/2022.
//

#ifndef GYMAPPLICATION_FEEDBACK_H
#define GYMAPPLICATION_FEEDBACK_H
#include "class.h"
#include "client.h"
#include "feed.h"
using namespace std;

class Feedback{
private:
    Class * classes;
    Client * client;
    Feed * feed;
public:
    Feedback(Class *classes, Client * client, Feed *  feed);
    Feedback(const Feedback& obj);
    ~Feedback();
    Class* getClass() const;
    void setClass(Class *classes);
    Client* getClient() const;
    void setClient(Client *client);
    void setFeed(Feed *feed);
    Feed* getFeed() const;
    bool pointer(void * ptr);
    bool operator == (const Feedback& obj) const;
};

#endif //GYMAPPLICATION_FEEDBACK_H
