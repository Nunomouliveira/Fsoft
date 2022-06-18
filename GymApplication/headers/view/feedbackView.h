//
// Created by migue on 10/06/2022.
//

#ifndef GYMAPPLICATION_FEEDBACKVIEW_H
#define GYMAPPLICATION_FEEDBACKVIEW_H
#include <list>
#include "feedback.h"
#include "clientContainer.h"
#include "classContainer.h"

class FeedbackView{
public:
    Feedback getFeedback(ClientContainer & clients, ClassContainer & classes);
    void printFeedback(Feedback *feedback);
    void printFeedbacks(list<Feedback>& feedbacks);
};
#endif //GYMAPPLICATION_FEEDBACKVIEW_H
