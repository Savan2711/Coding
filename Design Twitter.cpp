/*
https://leetcode.com/problems/design-twitter/description/
*/

// Time and Space Complexity: 
// Post a Tweet:
// Time: O(1) to add the tweet to the list.
// Space: O(1) for each tweet.
// Get News Feed:
// Time: O(F+TlogT), where F is the number of followees, and T is the total number of tweets considered (user's tweets + followees' tweets).
// Space: O(T) for the priority queue.
// Follow and Unfollow:
// Time: O(1) for insertions or deletions in the unordered_set.
// Space: O(1) for each follow/unfollow relationship.

class Twitter {
public:
    Twitter() : time(0) {

    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back(make_pair(time, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto it : tweets[userId]) {
            pq.push(it);
        }
        for(auto user : following[userId]) {
            for(auto tweet : tweets[user]) {
                pq.push(tweet);
            }
        }

        vector<int> news_feed;
        for(int i = 0; i < 10 && !pq.empty(); i++){
            news_feed.push_back(pq.top().second);
            pq.pop();
        }
        return news_feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

private:
    int time;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
    std::unordered_map<int, std::unordered_set<int>> following;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
