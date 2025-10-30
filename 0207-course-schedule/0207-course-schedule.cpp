class Solution {
public:

    int check(int currentCourse, vector<vector<int>>& adjecent, vector<int>& states){
        
        if(states[currentCourse] == 1){
            return 1;
        }
        else if(states[currentCourse] == 2){
            return 2;
        }
        else{ // state is not visited (== 0)

            if(adjecent[currentCourse].empty()){
                return 2;
            }

            states[currentCourse] = 1;

            unordered_set<int> results;
            for(int i = 0; i < adjecent[currentCourse].size(); i++){
                results.insert(check(adjecent[currentCourse][i], adjecent, states));
            }

            if(results.count(1)){
                return 1;
            }
            states[currentCourse] = 2;
            return 2;
        }
        
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjecent(numCourses);
        vector<int> states(numCourses, 0); //0 - notVisited, 1 - visiting, 2 - done
        vector<int> isPossible(numCourses);

        for(auto &pres : prerequisites){
            int course = pres[0];
            int preReq = pres[1];
            adjecent[preReq].push_back(course);
        }

        // 0 → [1]
        // 1 → [2]
        // 2 → [0]

        for(int i = 0; i < numCourses; i++){
            isPossible[i] = check(i, adjecent, states);
        }

        for(int i = 0; i < numCourses; i++){
            if(isPossible[i] == 1){
                return false;
            }
        }

        return true;
    }
};