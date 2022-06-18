//
// Created by migue on 10/06/2022.
//
#include <iostream>
#include "feedbackView.h"
#include "utils.h"
#include "InvalidDataException.h"
using namespace std;


Feedback FeedbackView::getFeedback(ClientContainer &clients, ClassContainer &classes) {
    Class class1("PIES","Pilates");
    Client client("Miguel",18);
    int feed=4;
    Feedback feedback(&class1,&client,feed);
    int number;
    string initials;
    int feed1;
    bool flag = false;
    do{
        try{
            flag = false;
            cout << "Enter client number: " ;
            cin >> number;
            Client *client1 = clients.get(number);
            feedback.setClient(client1);
            cout << "Enter Class Initials: ";
            cin >> initials;
            Class *class2 = classes.get(initials);
            feedback.setClass(class2);
            cout << "Enter Class Feedback: ";
            cin >> feed1;
            feedback.setFeed(feed1);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return feedback;
}

void FeedbackView::printFeedback(Feedback *feedback) {
    Client* client = feedback->getClient();
    Class* classes = feedback->getClass();
    int feed = feedback->getFeed();
    cout<<client->getNumber()<<". Name: "<<client->getName()<<" -> "<<classes->getInitials()<<" - "<<classes->getDenomination()<<" -> "<<feed<<"*"<<endl;
}

void FeedbackView::printFeedbacks(list<Feedback> &feedbacks) {
    for (list<Feedback>::iterator it=feedbacks.begin(); it != feedbacks.end(); ++it){
        printFeedback(&*it);
    }
}




