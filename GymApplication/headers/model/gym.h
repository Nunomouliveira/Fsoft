//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_GYM_H
#define GYMAPPLICATION_GYM_H
#include <string>
#include "SubjectContainer.h"
#include "StudentContainer.h"
#include "InstructorContainer.h"
#include "EnrollContainer.h"
using namespace std;

class School{
private :
    string name;
    SubjectContainer subjects;
    StudentContainer students;
    InstructorContainer instructors;
    EnrollContainer enrolls;

    void setDataForConsistency();
public:
    School();
    School(const string& name);
    School(const School& obj);
    const string& getName() const ;
    void setName(const string &name) ;

    SubjectContainer & getSubjectContainer();
    StudentContainer & getStudentContainer();
    InstructorContainer & getInstructorContainer();
    EnrollContainer & getEnrollContainer();

};



#endif //GYMAPPLICATION_GYM_H
