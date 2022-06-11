//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_LECTURE_H
#define GYMAPPLICATION_LECTURE_H
#include "class.h"
class Lecture{
private:
    Class * classes;
public:
    Lecture(Class * classes);
    Lecture(const Lecture& obj);
    ~Lecture();
    Class* getClass() const;
    void setClass(Class *classes);
    bool operator == (const Lecture& obj) const;
    bool operator == (const Class* ptr) const;
};


#endif //GYMAPPLICATION_LECTURE_H
