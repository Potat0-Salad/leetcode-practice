class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int,int> count;
        int majority = nums.size() / 2;

        for(int num : nums){
            count[num]++;
            if(count[num] > majority){
                return num;
            }
        }
        return -1;
    }
};