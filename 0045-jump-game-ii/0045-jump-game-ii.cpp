class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpcount = 0;
        int farthest = 0;
        int currentRange = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i > currentRange){
                jumpcount++;
                currentRange = farthest;
            }
            if(nums[i] + i > farthest){
                farthest = i + nums[i];
            }
        }

        return jumpcount;
    }
};