class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> counts;
        for(int i = 0; i < nums.size(); i++){
            auto it = counts.find(target - nums[i]);
            if(it != counts.end()){
                return {it->second, i};
            }
            counts[nums[i]] = i;
        }
        return {};
    }
};