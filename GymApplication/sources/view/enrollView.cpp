//
// Created by nunon on 09/06/2022.
//

#include <iostream>
#include "enrollView.h"
#include "utils.h"
#include "InvalidDataException.h"
using namespace std;


Enroll EnrollView::getEnroll(ClientContainer & client, ClassContainer & classes){
    Enroll enroll((Class *)1,(Client *)1);
    int number;
    string initials;
    bool flag = false;
    do{
        try{
            flag = false;
            cout << "Enter client number: " ;
            cin >> number;
            Client *clients = client.get(number);
            enroll.setClient(clients);
            cout << "Enter Class Initials: ";
            cin >> initials;
            Class *classet = classes.get(initials);
            enroll.setClass(classet);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return enroll;
}

void EnrollView::printEnroll(Enroll *enroll){
    Client *client = enroll->getClient();
    Class * classes = enroll->getClass();
    cout<<client->getNumber()<<". Nome:"<<client->getName()<<" -> "<<classes->getInitials()<<" - "<<classes->getDenomination()<<endl;
}
void EnrollView::printEnrolls(list<Enroll>& enrolls){
    for (list<Enroll>::iterator it=enrolls.begin(); it != enrolls.end(); ++it){
        printEnroll(&*it);
    }
}


