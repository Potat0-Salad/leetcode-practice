class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        else if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        int prevPrev = nums[0];
        int prev = max(nums[0], nums[1]);
        int currLoot = 0;

        for(int i = 2; i < nums.size(); i++){
            currLoot = max(nums[i] + prevPrev, prev);
            prevPrev = prev;
            prev = currLoot;
        }
        return currLoot;
    }
};