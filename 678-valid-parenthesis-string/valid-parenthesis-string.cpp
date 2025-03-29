class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;  // Stores indices of '('
        stack<int> star; // Stores indices of '*'

        // First pass: Match ')' with '(' or '*'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else { // s[i] == ')'
                if (st.size()>0) {
                    st.pop(); // Prefer matching '(' first
                } else if (star.size()>0) {
                    star.pop(); // Use '*' if no '(' left
                } else {
                    return false; // Unmatched ')'
                }
            }
        }

        // Second pass: Match remaining '(' with '*' (must appear after '(')
        while (!st.empty() && !star.empty()) {
            if (st.top() > star.top()) {
                return false; // '*' before '(' cannot balance
            }
            st.pop();
            star.pop();
        }

        // Valid only if all '(' are matched
       if(st.size()>0) return false;
      if(st.size()==0) return true;
      return true;
    }
};