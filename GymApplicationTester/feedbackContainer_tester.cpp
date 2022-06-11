//
// Created by migue on 10/06/2022.
//
#include "gtest/gtest.h"
#include "feedbackContainer.h"
#include "DuplicatedDataException.h"

TEST(FeedbackContainerAddTest, FeedbackValid) {
Feedback feedback ((Class*)1,(Client*)1,(Feed*)1);
FeedbackContainer container;
bool flag = true;
try{
container.add(feedback);
}catch(DuplicatedDataException& e){
flag = false;
}
EXPECT_TRUE(flag);
}
TEST(FeedbackContainAddTest, NoDuplicatedFeedback) {
    Feedback feedback ((Class*)1,(Client*)1,(Feed*)1);
    FeedbackContainer container;
    bool flag = true;
    try{
        container.add(feedback);
        container.add(feedback);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    EXPECT_FALSE(flag);
}



