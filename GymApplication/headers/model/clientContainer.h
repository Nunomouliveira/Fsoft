//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_CLIENTCONTAINER_H
#define GYMAPPLICATION_CLIENTCONTAINER_H
#include <list>
#include "client.h"
#include "enrollContainer.h"
#include "FeedbackContainer.h"
class ClientContainer{
private:
    list<Client> clients;
    EnrollContainer * enrolls;
    FeedbackContainer * feeds;
public:
    list<Client>::iterator search(int number);
    list<Client> getAll();
    Client* get(int number);
    void add(const Client& client);
    void remove(int number);
    void setEnrolls(EnrollContainer *enrolls);
    void setFeeds(FeedbackContainer *feeds);
};

#endif //GYMAPPLICATION_CLIENTCONTAINER_H
