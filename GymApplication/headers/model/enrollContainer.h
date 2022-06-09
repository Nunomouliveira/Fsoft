//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_ENROLLCONTAINER_H
#define GYMAPPLICATION_ENROLLCONTAINER_H
#include <list>
#include <tuple>
#include "enroll.h"

using namespace std;

class EnrollContainer{
private:
    list<Enroll> enrolls;
public:
    list<Enroll>::iterator search(int number, const string& initials);
    list<Enroll> getAll();
    Enroll* get(int number, const string& initials);
    list<tuple<Class *, int>> getClasses(int number);
    list<Client *> getClients(const string& initials);
    void add(const Enroll& obj);
    void remove(int number,const string& initials);
};

#endif //GYMAPPLICATION_ENROLLCONTAINER_H
