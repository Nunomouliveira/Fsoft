//
// Created by migue on 09/06/2022.
//
#include "gtest/gtest.h"
#include "DuplicatedDataException.h"
#include "enrollContainer.h"


TEST(EnrollContainerAddTest, EnrollValid) {
    Client client ("Miguel", 18);
    Class classes("PIES", "Pilates");
    Enroll enroll(&classes,&client);
    EnrollContainer container;
    bool flag = true;
    try{
        container.add(enroll);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    EXPECT_TRUE(flag);
}

TEST(EnrollContainerAddTest, NoDuplicatedEnroll) {
    Client client("Miguel", 18);
    Class classes("PIES","Pilates");
    Enroll enroll(&classes,&client);
    EnrollContainer container;
    bool flag = true;
    try{
        container.add(enroll);
        container.add(enroll);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    EXPECT_FALSE(flag);
}



TEST(EnrollContainerRemoveTest, NoDataConsistencyProblem) {
    Client client("Miguel",18);
    Class classes("PIES","Pilates");
    Enroll enroll(&classes,&client);
    EnrollContainer container;
    container.add(enroll);
    int nr = client.getNumber();
    string initials = classes.getInitials();
    bool flag = true;
    try{
        container.remove(nr,initials);
    }catch(DataConsistencyException& e){
        flag = false;
    }
    EXPECT_TRUE(flag);
}
