//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_LECTURECONTAINER_H
#define GYMAPPLICATION_LECTURECONTAINER_H
#include <list>
#include "class.h"
#include "lecture.h"

using namespace std;

class LectureContainer{
private:
    list<Lecture> lectures;
public:
    list<Lecture>::iterator search(const string& initials);
    list<Lecture> getAll();
    Lecture* get(const string& initials);
    void add(const Lecture& obj);
    void remove(const string& initials);
};

#endif //GYMAPPLICATION_LECTURECONTAINER_H
