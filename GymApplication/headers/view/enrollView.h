//
// Created by nunon on 09/06/2022.
//

#ifndef FSOFT2022_1A_4_ENROLLVIEW_H
#define FSOFT2022_1A_4_ENROLLVIEW_H

#include <list>
#include "enroll.h"
#include "clientContainer.h"
#include "classContainer.h"

class EnrollView{
public:
    Enroll getEnroll(ClientContainer & clients, ClassContainer & classes);
    void printEnroll(Enroll *enroll);
    void printEnrolls(list<Enroll>& enrolls);
    void printClassEnrolls(Class * classes, list<Client *>& clients);
};

#endif //FSOFT2022_1A_4_ENROLLVIEW_H
