class Solution {
public:
    int myAtoi(string s) {
        bool negative = false;
        bool numStart = false;
        uint64_t result = 0;

        for (int i = 0; i < s.size();) {
            if(isdigit(s[i]) || s[i] == '-' || s[i] == '+'){
                break;
            }
            if (s[i] == ' ')
                s.erase(i, 1);
            else
                i++;
        }
        
        if(s[0] != '-' && s[0] != '+' && !isdigit(s[0])){
            return 0;
        }

        if(s[0] == '-'){
            negative = true;
            s.erase(0, 1);
        }
        else if(s[0] == '+'){
            s.erase(0, 1);
        }

        for(int i = 0; i < s.size(); i++){
            if(!isdigit(s[i])){
                s.erase(i);
            }

            if(!numStart){
                if(s[i] == '0'){
                    if(s[i+1] == '-'){
                        s.erase(1);
                    }
                    else{
                        s.erase(0, 1);
                        i--;
                    }
                }
                else{
                    numStart = true;
                }
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(result == 0){
                result = s[i] - '0';
            }
            else{
                result = result * 10 + (s[i] - '0');

                    if ((!negative && result > 2147483647) || (negative && result > 2147483648))
                    return negative ? -2147483648 : 2147483647;
            }
        }

        if(negative == true){
            result = -result;
        }

        return result;
    }
};