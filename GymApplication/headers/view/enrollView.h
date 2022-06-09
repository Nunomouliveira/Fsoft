//
// Created by nunon on 09/06/2022.
//

#ifndef FSOFT2022_1A_4_ENROLLVIEW_H
#define FSOFT2022_1A_4_ENROLLVIEW_H

#include <list>
#include <tuple>
#include "../model/enroll.h"
#include "../model/clientContainer.h"
#include "../model/classContainer.h"

class EnrollView{
public:
    Enroll getEnroll(ClientContainer & clients, ClassContainer & classes);
    void printEnroll(Enroll *enroll);
    void printEnrolls(list<Enroll>& enrolls);
    void printClientEnrolls(Client * client, list<tuple<Class *, int>>& classes);
    void printClassEnrolls(Class * class, list<Client *>& clients);
};

#endif //FSOFT2022_1A_4_ENROLLVIEW_H
