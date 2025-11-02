class Solution {
public:
    int numCols;
    int numRows;

    void reaches(int currC, int currR, vector<vector<int>>& heights, vector<vector<bool>>& visited, int ocean){


        if(visited[currC][currR] == true){
            return;
        }
        
        visited[currC][currR] = true;

        if(currR != 0){
            if(heights[currC][currR - 1] >= heights[currC][currR]){
                reaches(currC, currR - 1, heights, visited, ocean);
            }
        }
        if(currR != numRows - 1){
            if(heights[currC][currR + 1] >= heights[currC][currR]){
                reaches(currC, currR + 1, heights, visited, ocean);
            }
        }
        if(currC != 0){
            if(heights[currC - 1][currR] >= heights[currC][currR]){
                reaches(currC - 1, currR, heights, visited, ocean);
            }
        }
        if(currC != numCols - 1){
            if(heights[currC + 1][currR] >= heights[currC][currR]){
                reaches(currC + 1, currR, heights, visited, ocean);
            }
        }

        return;
    }


    // 0 - pacific
    // 1 - atlantic
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        numCols = heights.size();
        numRows = heights[0].size();
        vector<vector<int>> result;

        vector<vector<bool>> visitedP(numCols, vector<bool> (numRows, false));
        vector<vector<bool>> visitedA(numCols, vector<bool> (numRows, false));

        for(int i = 0; i < numCols; i++){
            for(int j = 0; j < numRows; j++){
                if(i == 0){
                    reaches(i, j, heights, visitedP, 0);
                }
                else if(j == 0){
                    reaches(i, j, heights, visitedP, 0);
                }

                if(i == numCols - 1){
                    reaches(i, j, heights, visitedA, 1);
                }
                else if(j == numRows - 1){
                    reaches(i, j, heights, visitedA, 1);
                }
            }
        }

        for(int i = 0; i < numCols; i++){
            for(int j = 0; j < numRows; j++){
                if(visitedA[i][j] == true && visitedP[i][j] == true){
                    vector<int> cords;
                    cords.push_back(i);
                    cords.push_back(j);
                    result.push_back(cords);
                }
            }
        }
        return result;
    }
};
