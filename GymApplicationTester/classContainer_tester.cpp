//
// Created by migue on 09/06/2022.
//
#include "gtest/gtest.h"
#include "DuplicatedDataException.h"
#include "DataConsistencyException.h"
#include "classContainer.h"


TEST(ClassContainerAddTest, ClientValid) {
    Class classes("CHST", "Chest");
    ClassContainer container;
    bool flag = true;
    try{
        container.add(classes);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    if(flag == true){
        string initials = classes.getInitials();
        Class * ptr = container.get(initials);
        flag = (*ptr) == classes;
    }
    EXPECT_TRUE(flag);
}


TEST(ClassContainerAddTest, DuplicatedClass) {
    Class classes ("PIES", "Pilates");
    ClassContainer container;
    bool flag = true;
    try{
        container.add(classes);
        container.add(classes);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    EXPECT_FALSE(flag);
}



