//
// Created by migue on 09/06/2022.
//
#include "gtest/gtest.h"
#include "DuplicatedDataException.h"
#include "lectureContainer.h"


TEST(LectureContainerAddTest, LectureValid) {
    Lecture lecture ((Class*)1);
    LectureContainer container;
    bool flag = true;
    try{
        container.add(lecture);
    }catch(DuplicatedDataException& e){
        flag = false;
    }

    EXPECT_TRUE(flag);
}


TEST(LectureContainAddTest, NoDuplicatedLecture) {
    Class classes("PIES","Pilates");
    Lecture lecture(&classes);
    LectureContainer container;
    bool flag = true;
    try{
        container.add(lecture);
        container.add(lecture);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    EXPECT_FALSE(flag);
}



TEST(LectureContainerRemoveTest, NoDataConsistencyProblem) {
    Class classes("PIES","Pilates");
    Lecture lecture(&classes);
    LectureContainer lectureContainer;
    lectureContainer.add(lecture);
    string initials = classes.getInitials();
    bool flag = true;
    try{
        lectureContainer.remove(initials);
    }catch(DataConsistencyException& e){
        flag = false;
    }
    EXPECT_TRUE(flag);
}






