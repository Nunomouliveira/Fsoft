//
// Created by migue on 10/06/2022.
//

#ifndef GYMAPPLICATION_FEEDCONTAINER_H
#define GYMAPPLICATION_FEEDCONTAINER_H
#include <list>
#include "feed.h"
#include "feedbackContainer.h"

using namespace std;

class FeedContainer{
private:
    list<Feed> feeds;
    FeedbackContainer *feedbacks;
public:
    list<Feed>::iterator search(int feed);
    list<Feed> getAll();
    Feed* get(int feed);
    void add(const Feed& obj);
    void setFeedback(FeedbackContainer *feedbacks);

};
#endif //GYMAPPLICATION_FEEDCONTAINER_H
