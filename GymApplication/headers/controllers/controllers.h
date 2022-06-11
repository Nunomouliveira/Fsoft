//
// Created by raulr on 09/06/2022.
//

#ifndef GYMAPPLICATION_CONTROLLERS_H
#define GYMAPPLICATION_CONTROLLERS_H

#include "employeeView.h"
#include "clientView.h"
#include "view.h"
#include "enrollView.h"
#include "lectureView.h"
#include "gym.h"
#include "classView.h"
#include "feedbackView.h"

class Controller{
private:
    Gym model;
    ClientView clientView;
    EmployeeView employeeView;
    ClassView classView;
    EnrollView enrollView;
    LectureView lectureView;
    View view;
    FeedbackView feedbackView;
    void runClients();
    void runEmployees();
    void runClasses();
    void runEnrolls();
    void runLectures();
    void runFeedback();
public:
    Controller(Gym& gym);
    void run();
};

#endif //GYMAPPLICATION_CONTROLLERS_H
