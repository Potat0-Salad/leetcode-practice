class Solution {
public:
    string convert(string &s, int numRows) {
        vector<string> rows(numRows, "");
        int ct = 0;
        int currRow = 0;
        bool currDir = true; //true = down, false = up
        string result;

        if(numRows == 1){
            return s;
        }

        while(ct < s.size()){
            rows[currRow]+= s[ct];
            if(currDir == true && currRow < numRows - 1){
                currRow++;
            }
            else if(currDir == true && currRow == numRows - 1){
                currDir = !currDir; //change direction
                currRow--;
            }
            else if(currDir == false && currRow > 0){
                currRow--;
            }
            else if(currDir == false && currRow == 0){
                currDir = !currDir;
                currRow++;
            }
            ct++;
        }

        for(int i = 0; i < rows.size(); i++){
            result+= rows[i];
        }
        return result;
    }
};