class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxsL(height.size());
        vector<int> maxsR(height.size());

        int maxL = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > maxL) {
                maxL = height[i];
            }
            maxsL[i] = maxL;
        }

        int maxR = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            if (height[i] > maxR) {
                maxR = height[i];
            }
            maxsR[i] = maxR;
        }
        
        int total = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            total += min(maxsL[i], maxsR[i]) - height[i];
        }

        return total;
    }
};