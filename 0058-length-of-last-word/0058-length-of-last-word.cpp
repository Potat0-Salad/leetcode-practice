class Solution {
public:
    int lengthOfLastWord(string s){
        int counter = 0;

        for (int i = s.length() - 1; i >= 0; i--){
            if (s[i] != ' '){
                counter++;
            }
            else if (counter > 0){
                break;
            }
        }
        return counter;
    }
};