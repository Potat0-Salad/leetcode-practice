class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> next;
        int numCol = grid.size();
        int numRow = grid[0].size();

        if(numCol == 0 || numRow == 0){
            return -1;
        }

        unordered_set<int> poss;

        for(int i = 0; i < numCol; i++){
            for(int j = 0; j < numRow; j++){
                if(grid[i][j] == 2){
                    vector<int> current;
                    current.push_back(i);
                    current.push_back(j);
                    current.push_back(0);
                    next.push(current);
                    poss.insert(2);
                }
                if(grid[i][j] == 0){
                    poss.insert(0);
                }
                if(grid[i][j] == 1){
                    poss.insert(1);
                }
            }
        }
        if(poss.size() == 1){
            if(poss.count(0)){
                return 0;   
            }
            else if(poss.count(1)){
                return -1;
            }
        }

        if(next.empty()){
            return -1;
        }

        if(next.empty()){
            return 0;
        }

        int maxHops = -1;

        while(!next.empty()){
            int currC = next.front()[0];
            int currR = next.front()[1];
            int numHops = next.front()[2];
            next.pop();

            maxHops = max(maxHops, numHops);

            if(currC != 0 && grid[currC - 1][currR] == 1){
                vector<int> current;
                current.push_back(currC - 1);
                current.push_back(currR);
                current.push_back(numHops + 1);
                grid[currC - 1][currR] = 2;
                next.push(current);
            }
            if(currC != numCol - 1 && grid[currC + 1][currR] == 1){
                vector<int> current;
                current.push_back(currC + 1);
                current.push_back(currR);
                current.push_back(numHops + 1);
                grid[currC + 1][currR] = 2;
                next.push(current);
            }
            if(currR != 0 && grid[currC][currR - 1] == 1){
                vector<int> current;
                current.push_back(currC);
                current.push_back(currR - 1);
                current.push_back(numHops + 1);
                grid[currC][currR - 1] = 2;
                next.push(current);
            }
            if(currR != numRow - 1 && grid[currC][currR + 1] == 1){
                vector<int> current;
                current.push_back(currC);
                current.push_back(currR + 1);
                current.push_back(numHops + 1);
                grid[currC][currR + 1] = 2;
                next.push(current);
            }
        }

        for(int i = 0; i < numCol; i++){
            for(int j = 0; j < numRow; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }


        return maxHops;
    }
};