//
// Created by migue on 09/06/2022.
//

# include "gtest/gtest.h"
# include "client.h"
# include "InvalidDataException.h"

TEST(ClientConstructorTest, InvalidName) {
    bool flag = false;
    try{
        Client client ("", "18");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(ClientConstructorTest, ValidName) {
    bool flag = false;
    try{
        Client client ("Miguel", "18");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}

TEST(ClientSetNameTest, InvalidName) {
    Client client ("Miguel", "18");
    bool flag = false;
    try{
        client.setName("");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(ClientSetNameTest, ValidName) {
    Client client ("Miguel", "18");
    bool flag = false;
    try{
        Client client ("Nuno", "18");
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}
TEST(ClientOperatorEqualTest, EqualNrs) {
    Client client ("Miguel", "18");
    int nr = client.getNumber();
    bool flag = client==nr;
    EXPECT_TRUE(flag);
}
TEST(ClientOperatorEqualTest, NotEqualNrs) {
    Client client ("Miguel", "18");
    int nr = client.getNumber() +1;
    bool flag = client==nr;
    EXPECT_FALSE(flag);
}



