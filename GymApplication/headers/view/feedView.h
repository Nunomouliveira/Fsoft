//
// Created by migue on 10/06/2022.
//

#ifndef GYMAPPLICATION_FEEDVIEW_H
#define GYMAPPLICATION_FEEDVIEW_H
#include <list>
#include "feed.h"

class FeedView{
public:

    Feed getFeed();
    void printFeed(Feed *feed);
    void printFeeds(list<Feed>& feeds);
};
#endif //GYMAPPLICATION_FEEDVIEW_H
