//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_CLIENTCONTAINER_H
#define GYMAPPLICATION_CLIENTCONTAINER_H
#include <list>
#include "client.h"
#include "enrollContainer.h"

class ClientContainer{
private:
    list<Client> clients;
    EnrollContainer * enrolls;
public:
    list<Client>::iterator search(int number);
    list<Client> getAll();
    Client* get(int number);
    void add(const Client& obj);
    void remove(int number);
    void setEnrolls(EnrollContainer *enrolls);
};

#endif //GYMAPPLICATION_CLIENTCONTAINER_H
