//
// Created by nunon on 09/06/2022.
//

#ifndef FSOFT2022_1A_4_LECTUREVIEW_H
#define FSOFT2022_1A_4_LECTUREVIEW_H

#include <list>
#include "../model/lecture.h"
#include "../model/classContainer.h"

class LectureView{
public:
    Lecture getLecture(ClassContainer & classes);
    void printLecture(Lecture *lecture);
    void printLectures(Employee * employee, list<Lecture>& lectures);

#endif //FSOFT2022_1A_4_LECTUREVIEW_H
