//
// Created by migue on 09/06/2022.
//
#include "gtest/gtest.h"
#include "class.h"
#include "InvalidDataException.h"


TEST(ClassConstructorTest, ValidName) {
    bool flag = false;
    try{
        Class classes ("PIES", "Pilates");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}

TEST(ClassSetNameTest, InvalidName) {
    Class classes ("PIES", "Pilates");
    bool flag = false;
    try{
        classes.setInitials("a");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(ClassSetNameTest, ValidName) {
    Class classes ("PIES", "Pilates");
    bool flag = false;
    try{
        Class classes ("BYPP", "BodyPump");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}
TEST(ClassOperatorEqualTest, EqualInitials) {
    Class classes ("PIES", "Pilates");
    string initials = classes.getInitials();
    bool flag = classes==initials;
    EXPECT_TRUE(flag);
}
TEST(ClassOperatorEqualTest, NotEqualInitials) {
    Class classes ("PIES", "Pilates");
    string initials = classes.getInitials() +'A';
    bool flag = classes==initials;
    EXPECT_FALSE(flag);
}
TEST(ClassOperatorEqualTest, EqualDenomination) {
    Class classes ("PIES", "Pilates");
    const string& denomination = classes.getDenomination();
    bool flag = classes==denomination;
    EXPECT_FALSE(flag);
}
TEST(ClassOperatorEqualTest, NotEqualDenomination) {
    Class classes ("PIES", "Pilates");
    string denomination = classes.getDenomination() +'A';
    bool flag = classes==denomination;
    EXPECT_FALSE(flag);
}



