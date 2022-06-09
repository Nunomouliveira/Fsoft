//
// Created by nunon on 09/06/2022.
//

#include <iostream>
#include "EnrollView.h"
#include "Utils.h"
#include "InvalidDataException.h"
using namespace std;


Enroll EnrollView::getEnroll(ClientContainer & client, ClassContainer & classes){
    //this is very dangerous
    Enroll enroll((Class *)1,(Client *)1);
    bool flag = false;
    do{
        try{
            flag = false;
            cout<<"Enroll"<<endl;
            int number = Utils::getNumber("Enter Client Number");
            Client *clients = client.get(number);
            enroll.setClient(clients);
            string initials = Utils::getString("Enter Class Initials");
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
    cout<<to_string(client->getNumber())<<":"<<client->getName()<<":"<<classes->getInitials()<<":"<<classes->getDenomination()<<endl;
}
void EnrollView::printEnrolls(list<Enroll>& enrolls){
    for (list<Enroll>::iterator it=enrolls.begin(); it != enrolls.end(); ++it){
        printEnroll(&*it);
    }
}

void EnrollView::printClassEnrolls(Class *classes, list<Client *> &clients) {
    cout<<classes->getInitials()<<":"<<classes->getDenomination()<<endl;
    for (list<Client *>::iterator it=clients.begin(); it != clients.end(); ++it){
        cout<<"\t"<<to_string((*it)->getNumber())<<":"<<(*it)->getName()<<endl;
    }
}
