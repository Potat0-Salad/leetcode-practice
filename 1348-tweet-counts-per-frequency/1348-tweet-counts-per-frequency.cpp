class TweetCounts {
private:
    unordered_map<string, vector<int>> tweets;

public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if(tweets.count(tweetName) == 0){
            return vector<int>{0};
        }

        sort(tweets[tweetName].begin(), tweets[tweetName].end());

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

        int index = startTime;
        auto it = lower_bound(tweets[tweetName].begin(), tweets[tweetName].end(), index);

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