//
// Created by migue on 10/06/2022.
//

#ifndef GYMAPPLICATION_FEEDBACKCONTAINER_H
#define GYMAPPLICATION_FEEDBACKCONTAINER_H
#include <list>
#include "feedback.h"

using namespace std;

class FeedbackContainer{
private:
    list<Feedback> feedbacks;
public:
    list<Feedback>::iterator searchCla(int number, const string& initials);
    list<Feedback> getAll();
    Feedback* getCla(int number, const string& initials);
    void add(const Feedback& obj);
};
#endif //GYMAPPLICATION_FEEDBACKCONTAINER_H
