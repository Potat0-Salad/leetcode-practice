class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool result = false;
        int farthest = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > farthest){
                break;
            }
            if(nums[i] + i > farthest){
                farthest = i + nums[i];
            }
        }

        if(farthest >= nums.size() - 1 || nums.size() == 1) result = true;
        return result;
    }
};