#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

class Twitter {
public:
    unordered_map<int,set<int>> people;
    unordered_map<int,unordered_map<int,int>> tweets;
    int time = 0;
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert(make_pair(tweetId,time));
        time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ids;
        for(auto person : people[userId])
        {
            // for(auto tweet : tweets[userId])
            // {

            //     ids.push_back(tweet);
            // }
            // ids.push_back(tweet);
        }
        
        return ids;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        people[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(people[followerId].find(followeeId) !=people[followerId].end())
        {
            people[followerId].erase(followeeId);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    Twitter* obj = new Twitter();
    obj->postTweet(1,5);
    vector<int> param_2 = obj->getNewsFeed(1);
    obj->follow(1,2);
    obj->postTweet(2,6);
    vector<int> param_3 = obj->getNewsFeed(1);
    obj->unfollow(1,2);

}