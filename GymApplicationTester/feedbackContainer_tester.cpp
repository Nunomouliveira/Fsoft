//
// Created by migue on 10/06/2022.
//
#include "gtest/gtest.h"
#include "feedbackContainer.h"
#include "DuplicatedDataException.h"

TEST(FeedbackContainerAddTest, FeedbackValid) {
Class classes ("PIES", "Pilates");
Client client ("Miguel", 18);
int feed = 3;
Feedback feedback (&classes,&client,feed);
FeedbackContainer container;
bool flag = true;
try{
container.add(feedback);
}catch(DuplicatedDataException& e){
flag = false;
}
EXPECT_TRUE(flag);
}
TEST(FeedbackContainerAddTest, NoDuplicatedFeedback) {
    Class classes ("PIES", "Pilates");
    Client client ("Miguel", 18);
    int feed = 3;
    Feedback feedback (&classes,&client,feed);
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



