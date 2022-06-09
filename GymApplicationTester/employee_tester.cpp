//
// Created by migue on 09/06/2022.
//
#include "gtest/gtest.h"
#include "employee.h"
#include "InvalidDataException.h"

TEST(EmployeeConstructorTest, InvalidName) {
    bool flag = false;
    try{
        Employee employee ("a", "Miguel");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(EmployeeConstructorTest, ValidName) {
    bool flag = false;
    try{
        Employee employee ("MIEL", "Miguel");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}

TEST(EmployeeSetNameTest, InvalidName) {
    Employee employee ("MIEL", "Miguel");
    bool flag = false;
    try{
        employee.setName("a");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(EmployeeSetNameTest, ValidName) {
    Employee employees ("MIEL", "Miguel");
    bool flag = false;
    try{
        Employee employees ("NOLI", "Nuno");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}
TEST(EmployeeOperatorEqualTest, EqualInitials) {
    Employee employee ("MIEL", "Miguel");
    string initials = employee.getInitials();
    bool flag = employee==initials;
    EXPECT_TRUE(flag);
}
TEST(EmployeeOperatorEqualTest, NotEqualInitials) {
    Employee employee ("MIEL", "MIGUEL");
    string initials= employee.getInitials()+'A' ;
    bool flag = employee==initials;
    EXPECT_FALSE(flag);
}



