//
// Created by nunon on 09/06/2022.
//

#include <iostream>
#include "LectureView.h"
#include "Utils.h"
#include "InvalidDataException.h"
#include "lecture.h"
#include "classContainer.h"

using namespace std;


Lecture LectureView::getLecture(ClassContainer & classes){
    Lecture lecture((Class *)1);
    bool flag = false;
    do{
        try{
            flag = false;
            cout<<"Lecture"<<endl;
            string initials = Utils::getString("Enter Subject Initials");
            Class *classet = classes.get(initials);
            lecture.setClass(classet);

        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return lecture;
}

void LectureView::printLecture(Lecture *lecture){
    Class * classes = lecture->getClass();
    cout<<"\t"<<classes->getInitials()<<":"<<classes->getDenomination()<<endl;
}
void LectureView::printLectures(employee * employee, list<Lecture>& lectures){
    cout<<employee->getInitials()<<":"<<employee->getName()<<endl;
    for (list<Lecture>::iterator it=lectures.begin(); it != lectures.end(); ++it){
        printLecture(&*it);
    }
}
