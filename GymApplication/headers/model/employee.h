//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_EMPLOYEE_H
#define GYMAPPLICATION_EMPLOYEE_H
#include "person.h"
#include "lectureContainer.h"

class Employee : public Person{
private:
    string initials;
    LectureContainer lectures;
public:
    Employee(const string& initials, const string& name);
    Employee(const Employee& obj);
    ~Employee();
    const string& getInitials() const ;
    void setInitials(const string &initials) ;
    LectureContainer & getLectures();
    bool operator == (const Employee& obj) const;
    bool operator == (const string initials) const;
    bool ValidInitials(const string& initials);

};

#endif //GYMAPPLICATION_EMPLOYEE_H
