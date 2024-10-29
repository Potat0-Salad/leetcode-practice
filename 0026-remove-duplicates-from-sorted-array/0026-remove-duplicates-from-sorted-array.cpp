class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::vector<int>memory;
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 1000000){
                if(std::find(memory.begin(), memory.end(), nums[i]) != memory.end()){
                    nums[i] = 1000000;
                }
                else{
                    memory.push_back(nums[i]);
                    k++;
                }
            }
        }
        sort(nums.begin(), nums.end());
        return k;
    }
};