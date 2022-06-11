//
// Created by migue on 09/06/2022.
//
#include "gtest/gtest.h"
#include "enroll.h"
#include "InvalidDataException.h"


TEST(EnrollConstructorTest, ValidEnroll) {
bool flag = false;
try{
Enroll enroll ((Class*)1, (Client*)1);
}catch(InvalidDataException& e){
flag = true;
}
EXPECT_FALSE(flag);
}
TEST(EnrollConstructorTest, InvalidEnroll) {
    bool flag = false;
    try{
        Enroll enroll ((Class*)0, (Client*)1);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}
TEST(EnrollSetClassTest, InvalidEnroll) {
    Enroll enroll((Class*)1,(Client*)1);
    bool flag = false;
    try{
        enroll.setClass((Class*)0);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(EnrollSetClassTest, ValidEnroll) {
    Enroll enroll((Class*)1,(Client*)1);
    bool flag = false;
    try{
        enroll.setClass((Class*)1);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}
TEST(EnrollSetClientTest, InvalidEnroll) {
    Enroll enroll((Class*)1,(Client*)1);
    bool flag = false;
    try{
        enroll.setClient((Client*)0);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(EnrollSetClientTest, ValidEnroll) {
    Enroll enroll((Class*)1,(Client*)1);
    bool flag = false;
    try{
        enroll.setClient((Client*)1);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}



