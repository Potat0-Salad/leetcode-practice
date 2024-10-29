class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        std::replace(nums.begin(), nums.end(), val, 1000000);
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            std::cout << nums[i] << ", ";
            if(nums[i] == 1000000){
                break;
            }
            else{
                count++;
            }
        }
        return count;
    }
};