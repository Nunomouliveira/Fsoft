//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_ENROLL_H
#define GYMAPPLICATION_ENROLL_H
#include "class.h"
#include "client.h"

using namespace std;

class Enroll{
private:
    Class * classes;
    Client * client;
public:
    Enroll(Class *classes, Client * client);
    Enroll(const Enroll& obj);
    ~Enroll();
    Class* getClass() const;
    void setClass(Class *classes);
    Client* getClient() const;
    void setClient(Client *client);
    bool pointer(void * ptr);
    bool operator == (const Enroll& obj) const;
};

#endif //GYMAPPLICATION_ENROLL_H
