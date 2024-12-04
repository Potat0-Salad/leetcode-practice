class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        bool toggle = false;

        for(int i = s.length() - 1; i >= 0; i--){
            cout << i;
            if(!toggle){
                if(s[i] == ' '){}
                else{
                    counter++;
                    if(i == 0){
                        return counter;
                    }
                    toggle = true;
                }
            }
            else{
                if(s[i] != ' '){
                    counter++;
                }
                else{
                    return counter;
                }
            }

        }
        return counter;
    }
};