class Twitter {
private:
    deque<pair<int, int>> feed; //userid, postid
    unordered_map<int, unordered_set<int>> connections;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        feed.push_front({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        auto end_it = feed.end();
        auto it = feed.begin();

        while(it != end_it && result.size() < 10){
            if(connections[userId].contains(it->first) || userId == it->first){
                result.push_back(it->second);
            }

            it++;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        connections[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        connections[followerId].erase(followeeId);
        cout << "User " << followerId << " un-followed: " << followeeId << endl;
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