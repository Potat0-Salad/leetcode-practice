class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> each(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]){
                if(each[i] <= each[i - 1]){
                    each[i] = each[i - 1] + 1;
                }
            }
        }
        for(int i = each.size() - 2; i >= 0 ; i--){
            if(ratings[i] > ratings[i + 1]){
                if(each[i] <= each[i + 1]){
                    each[i] = each[i + 1] + 1;
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < each.size(); i++){
            sum += each[i];
        }
        return sum;
    }
};