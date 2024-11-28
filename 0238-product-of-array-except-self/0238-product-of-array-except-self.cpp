class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        answer[1] = nums[0];
        int suffix = 1;
        for(int i = 2; i < nums.size(); i++){
                answer[i] = answer[i - 1] * nums[i - 1];
        }
        cout << endl;
        for(int i = nums.size() - 2; i >= 0; i--){
            suffix *= nums[i + 1];
            answer[i] *= suffix;
        } 
        return answer;
    }
};