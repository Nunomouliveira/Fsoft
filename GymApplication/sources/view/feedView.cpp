//
// Created by migue on 10/06/2022.
//
#include <iostream>
#include "feedView.h"
#include "utils.h"
#include "InvalidDataException.h"
using namespace std;

Feed FeedView::getFeed(){
    Feed feed(0);
    bool flag = false;
    int feed1;
    do{
        try{
            flag = false;
            cout << "Enter Client Feed: ";
            cin >> feed1;
            feed.setFeed(feed1);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return feed;
}

void FeedView::printFeed(Feed *feed) {
    cout<<feed->getFeed()<<" *"<<endl;
}
void FeedView::printFeeds(list<Feed> &feeds) {
    for (list<Feed>::iterator it=feeds.begin(); it != feeds.end(); ++it){
        printFeed(&*it);
    }
}
