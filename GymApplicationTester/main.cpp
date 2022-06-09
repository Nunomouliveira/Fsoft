//
// Created by migue on 09/06/2022.
//

#include <iostream>
#include <gtest/gtest.h>
#include "client_tester.cpp"
#include "clientContainer_tester.cpp"
#include "employee_tester.cpp"
#include "employeeContainer_tester.cpp"
#include "class_tester.cpp"
//#include "ent_container_test.cpp"

int main(int argc, char *argv[]){
    :: testing:: InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}