class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::vector<int>memory;
        std::vector<int>memory2;
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 1000000){
                if(std::find(memory.begin(), memory.end(), nums[i]) != memory.end()){
                    if(std::find(memory2.begin(), memory2.end(), nums[i]) != memory2.end()){
                        nums[i] = 1000000;
                    }
                    else{
                        memory2.push_back(nums[i]);
                        k++; 
                    }
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