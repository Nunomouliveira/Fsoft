//
// Created by nunon on 09/06/2022.
//
#include <iostream>
#include "classView.h"
#include "utils.h"
#include "InvalidDataException.h"
using namespace std;


Class ClassView::getClass() {
    Class classes("Initials", "Name");
    string denomination;
    string initials;
    bool flag = false;
    do{
        try{
            flag = false;
            cout << "Enter Class Denomination: ";
            cin >> denomination;
            cout << "Enter Class Initials: ";
            cin >> initials;
            classes.setDenomination(denomination);
            classes.setInitials(initials);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return classes;
}

void ClassView::printClass(Class *classes) {
    cout<<classes->getDenomination()<<" - "<<classes->getInitials()<<endl;
}
void ClassView::printClasses(list<Class> &classes) {
    for (list<Class>::iterator it=classes.begin(); it != classes.end(); ++it){
        printClass(&*it);
    }
}

