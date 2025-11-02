class Solution {
public:
    int numCols;
    int numRows;

    //DISCLAIMER: I KNOW I ACCIDENTALLY SWAPPED THE COLS AND ROWS AROUND - IDK WHAT WAS I THINKING WHEN CODING THIS

    void reaches(int currC, int currR, vector<vector<int>>& heights, vector<vector<bool>>& visited){


        if(visited[currC][currR] == true){
            return;
        }
        
        visited[currC][currR] = true;

        if(currR != 0){
            if(heights[currC][currR - 1] >= heights[currC][currR]){
                reaches(currC, currR - 1, heights, visited);
            }
        }
        if(currR != numRows - 1){
            if(heights[currC][currR + 1] >= heights[currC][currR]){
                reaches(currC, currR + 1, heights, visited);
            }
        }
        if(currC != 0){
            if(heights[currC - 1][currR] >= heights[currC][currR]){
                reaches(currC - 1, currR, heights, visited);
            }
        }
        if(currC != numCols - 1){
            if(heights[currC + 1][currR] >= heights[currC][currR]){
                reaches(currC + 1, currR, heights, visited);
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
                    reaches(i, j, heights, visitedP);
                }
                else if(j == 0){
                    reaches(i, j, heights, visitedP);
                }

                if(i == numCols - 1){
                    reaches(i, j, heights, visitedA);
                }
                else if(j == numRows - 1){
                    reaches(i, j, heights, visitedA);
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
