#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Twitter {
private:
    struct Tweet {
        int id;
        int time;
    };


    unordered_map<int, vector<Tweet>> userTweets;
    unordered_map<int, unordered_set<int>> connections;
    int timer;

public:
    Twitter() : timer(0) {}

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({tweetId, timer++});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;

        addLatestToPQ(userId, pq);

        if (connections.contains(userId)) {
            for (int followeeId : connections[userId]) {
                addLatestToPQ(followeeId, pq);
            }
        }

        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            vector<int> top = pq.top();
            pq.pop();

            int tweetId = top[1];
            int authorId = top[2];
            int nextIdx = top[3] - 1;

            result.push_back(tweetId);

            if (nextIdx >= 0) {
                const Tweet& t = userTweets[authorId][nextIdx];
                pq.push({t.time, t.id, authorId, nextIdx});
            }
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            connections[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        connections[followerId].erase(followeeId);
    }

private:
    void addLatestToPQ(int userId, priority_queue<vector<int>>& pq) {
        if (userTweets.contains(userId) && !userTweets[userId].empty()) {
            int lastIdx = userTweets[userId].size() - 1;
            const Tweet& t = userTweets[userId][lastIdx];
            pq.push({t.time, t.id, userId, lastIdx});
        }
    }
};