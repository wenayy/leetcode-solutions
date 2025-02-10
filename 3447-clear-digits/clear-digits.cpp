class Solution {
public:
    string clearDigits(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])) st.push(s[i]);
            if(!isalpha(s[i])) st.pop();

        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
      reverse(ans.begin(),ans.end());
        return ans;
    }
};