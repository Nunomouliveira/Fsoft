//
// Created by migue on 10/06/2022.
//
#include <iostream>
#include "feedbackView.h"
#include "utils.h"
#include "InvalidDataException.h"
using namespace std;


Feedback FeedbackView::getFeedback(ClientContainer &clients, ClassContainer &classes, FeedbackContainer &feeds) {
    Feedback feedback((Class *)1,(Client *)1,0);
    int number;
    string initials;
    int feed;
    bool flag = false;
    do{
        try{
            flag = false;
            cout << "Enter client number: " ;
            cin >> number;
            Client *client = clients.get(number);
            feedback.setClient(client);
            cout << "Enter Class Initials: ";
            cin >> initials;
            Class *class1 = classes.get(initials);
            feedback.setClass(class1);
            cout << "Enter Class Feedback: ";
            cin >> feed;
            feedback.setFeed(feed);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return feedback;
}

void FeedbackView::printFeedback(Feedback *feedback) {
    Client *client = feedback->getClient();
    Class * classes = feedback->getClass();
    int feed = feedback->getFeed();
    cout<<client->getNumber()<<". Name: "<<client->getName()<<" -> "<<classes->getInitials()<<" - "<<classes->getDenomination()<<" -> "<<feed<<"*"<<endl;
}

void FeedbackView::printFeedbacks(list<Feedback> &feedbacks) {
    for (list<Feedback>::iterator it=feedbacks.begin(); it != feedbacks.end(); ++it){
        printFeedback(&*it);
    }
}




