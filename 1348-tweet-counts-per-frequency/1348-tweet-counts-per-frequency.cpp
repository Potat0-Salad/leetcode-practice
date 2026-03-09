class TweetCounts {
private:
    unordered_map<string, multiset<int>> tweets;

public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if(tweets.count(tweetName) == 0){
            return vector<int>{0};
        }

        int numChunks;
        int numSec;

        if(freq == "minute"){
            numSec = 60;
        }
        else if(freq == "hour"){
            numSec = 3600;
        }
        else{ //day
            numSec = 86400;
        }
        numChunks = (endTime - startTime) / numSec + 1;
        vector<int> result (numChunks, 0);

        auto it = tweets[tweetName].lower_bound(startTime);

        while(it != tweets[tweetName].end() && *it <= endTime){
            int currentChunk = (*it - startTime) / numSec;
            result[currentChunk]++;
            it++;
        }

        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */