class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(int i=0; i<n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                if(tokens[i] == "+")
                    st.push(operand1 + operand2);
                if(tokens[i] == "-")
                    st.push(operand1 - operand2);
                if(tokens[i] == "*")
                    st.push(operand1 * operand2);
                if(tokens[i] == "/")
                    st.push(operand1 / operand2);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
