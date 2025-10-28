class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted = strs;
        vector<vector<string>> results;
        unordered_set<string> done;

        if(strs.size() == 1){
            vector<string> answer;
            answer.push_back(strs[0]);
            results.push_back(answer);
            return results;
        }

        for (string &str : sorted) {
            sort(str.begin(), str.end());
        }

        unordered_map<string, vector<string>> map;

        for (int i = 0; i < sorted.size(); i++) {
            if (done.count(strs[i])) continue; // skip if already grouped

            for (int j = 0; j < sorted.size(); j++) {
                if (sorted[i] == sorted[j]) {
                    map[sorted[i]].push_back(strs[j]);
                    done.insert(strs[j]);
                }
            }
        }

        for (auto pair : map) {
            string key = pair.first;
            vector<string> &s = pair.second;
            vector<string> currentVec;
            for (auto &val : s) {
                currentVec.push_back(val);
            }
            sort(currentVec.begin(), currentVec.end());
            results.push_back(currentVec);
        }

        return results;
    }
};