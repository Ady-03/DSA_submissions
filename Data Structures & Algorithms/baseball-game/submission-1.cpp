class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;

        for(int i=0; i<n; i++){
            if(operations[i] == "+" || operations[i] == "D" || operations[i] == "C"){
                int last = st.top();

                if(operations[i] == "+"){
                    int op2 = st.top();
                    st.pop();
                    int op1 = st.top();
                    st.push(op2);
                    st.push(op1+op2);
                }
                if(operations[i] == "D"){
                    st.push(last*2);
                }
                if(operations[i] == "C"){
                    st.pop();
                }
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};