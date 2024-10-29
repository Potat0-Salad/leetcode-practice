class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 0;
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                k++;
                counter++;
            }
            else if(nums[i] == nums[i - 1] && counter >= 2){
                nums[i - 1] = 1000000; //i - 1 so in case the next one is repeating, the 1000000 will not disturb
                counter++;
            }
            else if(nums[i] == nums[i - 1]){
                counter++;
                k++;
            }
            else{
                k++;
                counter = 1;
            }
        }
        
        sort(nums.begin(), nums.end());
        return k;
    }
};