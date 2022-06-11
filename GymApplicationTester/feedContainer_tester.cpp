//
// Created by migue on 10/06/2022.
//
#include "gtest/gtest.h"
#include "DuplicatedDataException.h"
#include "FeedContainer.h"


TEST(FeedContainerAddTest, FeedValid) {
    Feed feed (1);
    FeedContainer container;
    bool flag = true;
    try{
        container.add(feed);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    if(flag == true){
        int nr = feed.getFeed();
        Feed * ptr = container.get(nr);
        flag = (*ptr) == feed;
    }
    EXPECT_TRUE(flag);
}
TEST(FeedContainerAddTest, FeedInvalid) {
    Feed feed (6);
    FeedContainer container;
    bool flag = true;
    try{
        container.add(feed);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    if(flag == true){
        int nr = feed.getFeed();
        Feed * ptr = container.get(nr);
        flag = (*ptr) == feed;
    }
    EXPECT_FALSE(flag);
}





