class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int left = 0;

        unordered_set<char> seen;

        for(int right = 0; right < s.size(); right++){
            if(seen.count(s[right])){
                while(seen.count(s[right])){
                    seen.erase(s[left]);
                    left++;
                }
            }
            seen.insert(s[right]);
            if(seen.size() > longest){
                longest = seen.size();
            }
        }

        return longest;
    }
};