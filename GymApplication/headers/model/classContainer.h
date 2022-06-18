//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_CLASSCONTAINER_H
#define GYMAPPLICATION_CLASSCONTAINER_H
#include <vector>
#include <list>
#include "class.h"
#include "enrollContainer.h"
#include "employeeContainer.h"
#include "feedbackContainer.h"
using namespace std;

class ClassContainer{
private:
    list<Class> classes;
    EnrollContainer *enrolls;
    EmployeeContainer *employees;
    FeedbackContainer *feeds;
public:
    list<Class>::iterator search(const string& initials);
    list<Class> getAll();
    Class* get(const string& initials);
    void add(const Class& obj);
    void remove(const string& initials);
    void setEnrolls(EnrollContainer *enrolls);
    void setEmployees(EmployeeContainer *employees);
    void setFeeds(FeedbackContainer *feeds);
};

#endif //GYMAPPLICATION_CLASSCONTAINER_H
