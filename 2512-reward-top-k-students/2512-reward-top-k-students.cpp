class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string>positive(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string>negative(negative_feedback.begin(), negative_feedback.end());
        map<int,int> stats;
        vector<int> result;

        for (int id : student_id) {
            stats[id] = 0;
        }

        for(int i = 0; i < report.size(); i++){
            stringstream ss(report[i]);
            string word;

            while(ss >> word){
                if (positive.find(word) != positive.end()) {
                    stats[student_id[i]] += 3;
                } 
                else if (negative.find(word) != negative.end()) {
                    stats[student_id[i]] -= 1;
                }
            }
        }

        for(int i = 0; i < k; i++){
            auto max_it = max_element(
                stats.begin(), stats.end(),
                [](const auto &a, const auto &b) {
                if (a.second != b.second)
                    return a.second < b.second;
                return a.first > b.first;
                }
            );
            if(max_it != stats.end()){
                result.push_back(max_it->first);
                stats.erase(max_it);
            }
        }
        return result;
    }
};