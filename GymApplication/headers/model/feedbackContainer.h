//
// Created by migue on 10/06/2022.
//

#ifndef GYMAPPLICATION_FEEDBACKCONTAINER_H
#define GYMAPPLICATION_FEEDBACKCONTAINER_H
#include <list>
#include <tuple>
#include "feedback.h"

using namespace std;

class FeedbackContainer{
private:
    list<Feedback> feedbacks;
public:
    list<Feedback>::iterator search(int number, const string& initials, int feed);
    list<Feedback> getAll();
    Feedback* get(int number, const string& initials, int feed);
    void add(const Feedback& obj);
};
#endif //GYMAPPLICATION_FEEDBACKCONTAINER_H
