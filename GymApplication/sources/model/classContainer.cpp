//
// Created by migue on 09/06/2022.
//
#include "DuplicatedDataException.h"
#include "classContainer.h"
#include "DataConsistencyException.h"

int ClassContainer::search(const string& initials){
    for (unsigned i=0; i<this->classes.size(); ++i){
        if( this->classes[i] == initials){
            return i;
        }
    }
    return -1;
}
list<Class> ClassContainer::getAll(){
    list<Class> list;
    for (vector<Class>::iterator it = this->classes.begin(); it != this->classes.end(); ++it){
        list.push_back(*it);
    }
    return list;
}
Class* ClassContainer::get(const string& initials){
    Class *classes = NULL;
    int i = search(initials);
    if(i != -1){
        classes = &this->classes[i];
    }
    return classes;
}
void ClassContainer::add(const Class& obj){
    int i = search(obj.getInitials());
    if(i == -1){
        this->classes.push_back(obj);
    }else{
        string msg = "Class: " + obj.getInitials();
        throw DuplicatedDataException(msg);
    }

}
void ClassContainer::remove(const string& initials){
    list<Class *> listEnrolls;
    bool exist;
    int i = search(initials);
    if(i != -1){
        exist = this->employees->anyClass(initials);
        if(listEnrolls.size() == 0 && exist==false){
            this->classes.erase(this->classes.begin() + i);
        }else{
            string msg = "Class: " + initials;
            throw DataConsistencyException(msg);

        }
    }
}


void ClassContainer::setEnrolls(EnrollContainer *enrolls){
    this->enrolls = enrolls;
}
void ClassContainer::setEmployees(EmployeeContainer *employees) {
    this->employees = employees;
}
void ClassContainer::setFeeds(FeedContainer *feeds) {
    this->feeds = feeds;
}


