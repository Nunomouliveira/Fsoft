//
// Created by migue on 10/06/2022.
//

#ifndef GYMAPPLICATION_FEED_H
#define GYMAPPLICATION_FEED_H
using namespace std;
class Feed {
private:
    int feed;
public:
    Feed(int feed);
    Feed(const Feed& obj);
    ~Feed();
    const int getFeed() const;
    void setFeed(const int feed);
    bool operator == (const Feed& obj) const;
    bool operator == (const int nr) const;
    bool ValidFeed(const int feed);
};
#endif //GYMAPPLICATION_FEED_H
