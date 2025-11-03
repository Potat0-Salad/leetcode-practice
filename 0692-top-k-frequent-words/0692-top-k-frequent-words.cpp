class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        auto cmp = [](const pair<int,string>& a, const pair<int,string>& b){
            if (a.first != b.first) return a.first > b.first; // smaller freq at top
            return a.second < b.second;                       // on tie, larger word at top (so smaller survives)
        };

        unordered_map<string, int> mp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        vector<string> result;

        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }

        for(auto &item : mp){
            pq.push({item.second, item.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};