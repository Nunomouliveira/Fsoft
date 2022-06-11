//
// Created by migue on 09/06/2022.
//
#include "gtest/gtest.h"
#include "lecture.h"
#include "InvalidDataException.h"


TEST(LectureConstructorTest, ValidLecture) {
    bool flag = false;
    try{
        Lecture Lecture ((Class*)1);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}
TEST(LectureConstructorTest, InvalidLecture) {
    bool flag = false;
    try{
        Lecture lecture ((Class*)0);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}
TEST(LectureSetClassTest, InvalidLecture) {
    Lecture lecture((Class*)1);
    bool flag = false;
    try{
        lecture.setClass((Class*)0);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(LectureSetClassTest, ValidLecture) {
    Lecture lecture((Class*)1);
    bool flag = false;
    try{
        lecture.setClass((Class*)1);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}