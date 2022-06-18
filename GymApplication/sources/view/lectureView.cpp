//
// Created by nunon on 09/06/2022.
//

#include <iostream>
#include "lectureView.h"
#include "utils.h"
#include "InvalidDataException.h"
#include "lecture.h"
#include "classContainer.h"

using namespace std;


Lecture LectureView::getLecture(ClassContainer & classes){
    Class class1("PIES", "Pilates");
    Lecture lecture(&class1);
    string initials;
    bool flag = false;
    do{
        try{
            flag = false;
            cout << "Enter Class Initials: ";
            cin >> initials;
            Class *class2 = classes.get(initials);
            lecture.setClass(class2);

        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return lecture;
}

void LectureView::printLecture(Lecture *lecture){
    Class * classes = lecture->getClass();
    cout<<classes->getDenomination()<<" - "<<classes->getInitials()<<endl;
}
void LectureView::printLectures(Employee * employee, list<Lecture>& lectures){
    cout<<employee->getInitials()<<":"<<employee->getName()<<endl;
    for (list<Lecture>::iterator it=lectures.begin(); it != lectures.end(); ++it){
        printLecture(&*it);
    }
}
