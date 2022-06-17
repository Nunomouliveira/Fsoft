//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_GYM_H
#define GYMAPPLICATION_GYM_H
#include <string>
#include "classContainer.h"
#include "clientContainer.h"
#include "employeeContainer.h"
#include "enrollContainer.h"
#include "feedbackContainer.h"
using namespace std;

class Gym{
private :
    string name;
    ClassContainer classes;
    ClientContainer clients;
    EmployeeContainer employees;
    EnrollContainer enrolls;
    FeedbackContainer feedback;
    void setDataForConsistency();
public:
    Gym();
    Gym(const string& name);
    Gym(const Gym& obj);
    const string& getName() const ;
    void setName(const string &name) ;

    ClassContainer & getClassContainer();
    ClientContainer & getClientContainer();
    EmployeeContainer & getEmployeeContainer();
    EnrollContainer & getEnrollContainer();
    FeedbackContainer & getFeedbackContainer();

};



#endif //GYMAPPLICATION_GYM_H
