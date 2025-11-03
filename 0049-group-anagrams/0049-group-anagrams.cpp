class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        vector<vector<string>> results;
        for (auto& kv : groups) {
            sort(kv.second.begin(), kv.second.end());
            results.push_back(kv.second);
        }

        return results;
    }
};
