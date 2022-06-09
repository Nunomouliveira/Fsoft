//
// Created by nunon on 09/06/2022.
//
#include <iostream>
#include "ClassView.h"
#include "Utils.h"
#include "InvalidDataException.h"
using namespace std;


Class ClassView::getClass() {
    Class classes("Initials", "Name");
    bool flag = false;
    do{
        try{
            flag = false;
            cout<<"Class"<<endl;
            string denomination = Utils::getString("Denomination");
            string initials = Utils::getString("Initials");
            classes.setDenomination(denomination);
            classes.setInitials(initials);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return classes;
}

void ClassView::printClass(Class *classes) {
    cout<<classes->getInitials()<<":"<<classes->getDenomination()<<endl;
}
void ClassView::printClasses(list<Class> &classes) {
    for (list<Class>::iterator it=classes.begin(); it != classes.end(); ++it){
        printClass(&*it);
    }
}

