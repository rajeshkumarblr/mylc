#include <set>
#include <cmath>
#include <map>
#include <nlohmann/json.hpp>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 *
 * Difficulty: Medium
 * Category: heap
 * URL: https://leetcode.com/problems/design-twitter/
 *
 * Description:
 * Design a simplified version of Twitter where users can post tweets,
 * follow/unfollow another user, and is able to see the  10  most recent
 * tweets in the user's news feed.
 *  Implement the  Twitter  class:
 *           Twitter()  Initializes your twitter object.
 *           void postTweet(int userId, int tweetId)  Composes a new tweet
 * with ID  tweetId  by the user  userId . Each call to this function will be
 * made with a unique  tweetId .
 *           List<Integer> getNewsFeed(int userId)  Retrieves the  10  most
 * recent tweet IDs in the user's news feed. Each item in the news feed must
 * be posted by users who the user followed or by the user themself. Tweets
 * must be  ordered from most recent to least recent .
 *           void follow(int followerId, int followeeId)  The user with ID
 * followerId  started following the user with ID  followeeId .
 *           void unfollow(int followerId, int followeeId)  The user with ID
 * followerId  started unfollowing the user with ID  followeeId .
 *   Example 1:
 *  Input
 * ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet",
 * "getNewsFeed", "unfollow", "getNewsFeed"]
 * [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
 *  Output
 * [null, null, [5], null, null, [6, 5], null, [5]]
 *  Explanation
 * Twitter twitter = new Twitter();
 * twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
 * tweet id -> [5]. return [5]
 * twitter.follow(1, 2);    // User 1 follows user 2.
 * twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2
 * tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is
 * posted after tweet id 5.
 * twitter.unfollow(1, 2);  // User 1 unfollows user 2.
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
 * tweet id -> [5], since user 1 is no longer following user 2.
 *   Constraints:
 *           1 <= userId, followerId, followeeId <= 500
 *           0 <= tweetId <= 10 4
 *          All the tweets have  unique  IDs.
 *          At most  3 * 10 4   calls will be made to  postTweet ,
 * getNewsFeed ,  follow , and  unfollow .
 *          A user cannot follow himself.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;


// @lc code=start
class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        
    }
    
    vector<int> getNewsFeed(int userId) {
        
    }
    
    void follow(int followerId, int followeeId) {
        
    }
    
    void unfollow(int followerId, int followeeId) {
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end


int main() {
    try {
        json j = json::parse(R"raw({
  "cases": []
})raw");
        for (const auto &tc : j.at("cases")) {
            const auto &commands = tc.at("commands");
            const auto &args = tc.contains("arguments") ? tc.at("arguments") : tc.at("args");
            const auto &expected = tc.at("expected");
            Twitter* obj = nullptr;
            for (size_t i = 0; i < commands.size(); ++i) {
                string cmd = commands[i].get<string>();
                if (cmd == "Twitter") {
                    if (obj) delete obj;
                    obj = new Twitter();
                } else if (cmd == "postTweet") {
                    obj->postTweet(args[i][0].get<int>(), args[i][1].get<int>());
                } else if (cmd == "getNewsFeed") {
                    vector<int> got = obj->getNewsFeed(args[i][0].get<int>());
                    vector<int> exp = expected[i].get<vector<int>>();
                    if (got != exp) { cerr << "FAIL getNewsFeed" << endl; return 1; }
                } else if (cmd == "follow") {
                    obj->follow(args[i][0].get<int>(), args[i][1].get<int>());
                } else if (cmd == "unfollow") {
                    obj->unfollow(args[i][0].get<int>(), args[i][1].get<int>());
                }
            }
            if (obj) delete obj;
        }
        cout << "PASS" << endl;
        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 4;
    }
}
