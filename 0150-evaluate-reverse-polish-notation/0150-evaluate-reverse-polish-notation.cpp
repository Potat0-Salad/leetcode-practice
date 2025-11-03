class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "+" && tokens[i] != "-"){
                st.push(tokens[i]);
                continue;
            }
            string opr = tokens[i];
            string var2 = st.top();
            st.pop();
            string var1 = st.top();
            st.pop();
            int result;

            if(opr == "*"){
                result = stoi(var1) * stoi(var2);
            }
            else if(opr == "/"){
                result = stoi(var1) / stoi(var2);
            }
            else if(opr == "+"){
                result = stoi(var1) + stoi(var2);
            }
            else if(opr == "-"){
                result = stoi(var1) - stoi(var2);
            }

            st.push(to_string(result));
        }
        return stoi(st.top());
    }
};