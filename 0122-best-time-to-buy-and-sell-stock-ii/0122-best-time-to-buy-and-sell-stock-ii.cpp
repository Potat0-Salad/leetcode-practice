class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minPrice = prices[0];
        int totalProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i - 1]){
                totalProfit += prices[i] - prices[i - 1];
            }
        }
        return totalProfit;
    }
};