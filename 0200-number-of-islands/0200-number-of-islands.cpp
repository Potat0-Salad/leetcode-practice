class Solution {
public:

    int numCols;
    int numRows;

    void islandCheck(vector<vector<char>> &grid, int currRow, int currCol){
        grid[currRow][currCol] = '0';

        if(currRow != 0 && grid[currRow-1][currCol] == '1'){
            islandCheck(grid, currRow - 1, currCol);
        }
        if(currRow != numRows - 1 && grid[currRow+1][currCol] == '1'){
            islandCheck(grid, currRow + 1, currCol);
        }
        if(currCol != 0 && grid[currRow][currCol-1] == '1'){
            islandCheck(grid, currRow, currCol - 1);
        }
        if(currCol != numCols - 1 && grid[currRow][currCol+1] == '1'){
            islandCheck(grid, currRow, currCol + 1);
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        numRows = grid.size();
        numCols = grid[0].size();

        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(grid[i][j] == '1'){
                    count++;
                    islandCheck(grid, i, j);
                }
            }
        }
        return count;
    }
};