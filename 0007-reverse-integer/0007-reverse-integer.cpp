class Solution {
public:
    int reverse(int x) {
        string x_str = to_string(x);
        string result = "";
        int int_result;

        if(x_str[0] == '-'){
            result += '-';
            x_str.erase(0,1);
        }

        std::reverse(x_str.begin(), x_str.end());

        result += x_str;

        try{
            int_result = stoi(result);
        }
        catch(std::out_of_range& e){
            return 0;
        }
        
        return int_result;

    }
};