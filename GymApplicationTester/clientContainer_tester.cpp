//
// Created by migue on 09/06/2022.
//
#include "gtest/gtest.h"
#include "DuplicatedDataException.h"
#include "DataConsistencyException.h"
#include "clientContainer.h"


TEST(ClientContainerAddTest, ClientValid) {
    Client client ("Miguel", "18");
    ClientContainer container;
    bool flag = true;
    try{
        container.add(client);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    if(flag == true){
        int nr = client.getNumber();
        Client * ptr = container.get(nr);
        flag = (*ptr) == client;
    }
    EXPECT_TRUE(flag);
}


TEST(ClientContainerAddTest, DuplicatedClient) {
    Client client ("Miguel", "18");
    ClientContainer container;
    bool flag = true;
    try{
        container.add(client);
        container.add(client);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    EXPECT_FALSE(flag);
}

TEST(ClientContainerRemoveTest, NoDataConsistencyProblem) {
    Client client ("Maria", "18");
    Client client1 ("Nuno", "18");
    Class classes ("XXXX", "XXXXXXXXXXXXXX");
    Enroll enroll(&classes, &client);
    EnrollContainer enrollContainer;
    enrollContainer.add(enroll);
    ClientContainer container;
    container.setEnrolls(&enrollContainer);
    container.add(client);
    container.add(client1);
    int nr = client1.getNumber();
    bool flag = true;
    try{
        container.remove(nr);
    }catch(DataConsistencyException& e){
        flag = false;
    }
    if(flag == true){
        Client * ptr = container.get(nr);
        if(ptr != NULL)
            flag = false;
    }
    EXPECT_TRUE(flag);
}

TEST(ClientContainerRemoveTest, DataConsistencyProblem) {
    Client client ("Miguel", "18");
    Class classes ("XXXX", "XXXXXXXXXXXXXXXXXXX");
    Enroll enroll(&classes, &client);
    EnrollContainer enrollContainer;
    enrollContainer.add(enroll);
    ClientContainer container;
    container.setEnrolls(&enrollContainer);
    container.add(client);
    int nr = client.getNumber();
    bool flag = true;
    try{
        container.remove(nr);
    }catch(DataConsistencyException& e){
        flag = false;
    }
    EXPECT_FALSE(flag);
}





