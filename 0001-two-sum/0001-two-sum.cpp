class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> counts;
        for(int i = 0; i < nums.size(); i++){
            if(counts.contains(target - nums[i])){
                return{counts[target - nums[i]], i};
            }
            counts[nums[i]] = i;
        }
        return {};
    }
};