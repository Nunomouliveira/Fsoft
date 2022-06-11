//
// Created by migue on 10/06/2022.
//

# include "gtest/gtest.h"
# include "feed.h"
# include "InvalidDataException.h"

TEST(FeedConstructorTest, InvalidFeed) {
    bool flag = false;
    try{
        Feed feed (111);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(FeedConstructorTest, ValidFeed) {
    bool flag = false;
    try{
        Feed feed (1);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}

TEST(FeedSetFeedTest, InvalidFeed) {
    Feed feed (5);
    bool flag = false;
    try{
        feed.setFeed(7);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(FeedSetFeedTest, ValidFeed) {
    Feed feed (1);
    bool flag = false;
    try{
        Feed feed (5);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}


