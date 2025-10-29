class Solution {
public:
    string longestPalindrome(string s) {
        int l;
        int r;
        string result;
        string longest;
        for(int i = 0; i < s.size(); i++){

            //odd
            l = i;
            r = i;
            bool start = true;
            result.clear(); 
            while(l >= 0 && r < s.size()){
                if(s[l] == s[r]){
                    if(start == true){
                        result += s[r];
                        start = false;
                    }
                    else{
                        result += s[r];
                        result = s[l] + result;
                    }
                    l--;
                    r++;
                    if(result.size() > longest.size()){
                        longest = result;
                    }
                }
                else{
                    result = "";
                    start = true;
                    break;
                }
            }

            //even
            l = i;
            r = i + 1;
            result.clear(); 
            while(l >= 0 && r < s.size()){
                if(s[l] == s[r]){
                    result += s[r];
                    result = s[l] + result;
                    l--;
                    r++;
                    if(result.size() > longest.size()){
                    longest = result;
                    }
                }
                else{
                    result = "";
                    break;
                }
            }
        } 
        return longest;
    }
};