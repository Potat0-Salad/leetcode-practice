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

        while(ct <= s.size() - 1){
            if(currDir == true && currRow < numRows - 1){
                rows[currRow]+= s[ct];
                currRow++;
            }
            else if(currDir == true && currRow == numRows - 1){
                currDir = !currDir; //change direction
                rows[currRow]+= s[ct];
                currRow--;
            }
            else if(currDir == false && currRow > 0){
                rows[currRow]+= s[ct];
                currRow--;
            }
            else if(currDir == false && currRow == 0){
                currDir = !currDir;
                rows[currRow]+= s[ct];
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