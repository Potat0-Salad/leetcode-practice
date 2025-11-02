class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        vector<pair<int, int>> countsVec;
        map<int,int> counts;

        if(nums.empty()){
            return result;
        }

        for(int i = 0; i < nums.size(); i++){
            counts[nums[i]]++;
        }

        for(auto &entry : counts){
            countsVec.push_back({entry.second, entry.first}); // {num occurences, number}
        }

        sort(countsVec.begin(), countsVec.end());

        for (int i = 0; i < k; ++i){
            result.push_back(countsVec[countsVec.size() - 1 - i].second);
        }

        return result;
    }
};
