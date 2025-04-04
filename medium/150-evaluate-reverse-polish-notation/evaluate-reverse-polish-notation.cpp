class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            if (isdigit(tokens[i][0]) || (tokens[i].size() > 1 && tokens[i][0] == '-')) {
                st.push(stoi(tokens[i]));  // Handle negative numbers too
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                switch (tokens[i][0]) {
                    case '+': st.push(a + b); break;
                    case '-': st.push(a - b); break;
                    case '*': st.push(a * b); break;
                    case '/': st.push(a / b); break;  // Assume valid input (b ≠ 0)
                }
            }
        }

        return st.top();
    }
};