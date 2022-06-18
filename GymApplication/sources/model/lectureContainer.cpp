//
// Created by migue on 09/06/2022.
//
#include "DuplicatedDataException.h"
#include "lectureContainer.h"

list<Lecture>::iterator LectureContainer::search(const string& initials){
    Class * classes;
    list<Lecture>::iterator it = this->lectures.begin();
    for (; it != this->lectures.end(); ++it){
        classes = it->getClass();
        if(*(classes) == initials){
            return it;
        }
    }
    return it;
}
list<Lecture>  LectureContainer::getAll(){
    list<Lecture> newlist (this->lectures);
    return newlist;
}
Lecture*  LectureContainer::get(const string& initials){
    list<Lecture>::iterator it = search(initials);
    if(it != this->lectures.end()){
        return &*it;
    }
    return NULL;
}
void  LectureContainer::add(const Lecture& obj){
    Class* classes = obj.getClass();
    list<Lecture>::iterator it = search(classes->getInitials());
    if(it == this->lectures.end()){
        this->lectures.push_back(obj);
    }else{
        string msg = "Lecture: " + classes->getInitials();
        throw  DuplicatedDataException(msg);
    }

}
void  LectureContainer::remove(const string& initials){
    list<Lecture>::iterator it = search(initials);
    if(it != this->lectures.end()){
        this->lectures.erase(it);
    }
}



