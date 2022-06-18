//
// Created by migue on 09/06/2022.
//


#include <gtest/gtest.h>
#include "client_tester.cpp"
#include "clientContainer_tester.cpp"
#include "employee_tester.cpp"
#include "employeeContainer_tester.cpp"
#include "class_tester.cpp"
#include "classContainer_tester.cpp"
#include "enroll_tester.cpp"
#include "lecture_tester.cpp"
#include "feedback_tester.cpp"
#include "lectureContainer_tester.cpp"
#include "enrollContainer_tester.cpp"
#include "feedbackContainer_tester.cpp"

int main(int argc, char *argv[]){
    :: testing:: InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}