class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++){
            std::replace(nums1.begin() + m + i, nums1.begin() + m + i + 1, 0, nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
    }
};