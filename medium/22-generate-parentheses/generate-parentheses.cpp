class Solution {
public:
bool isvalid(string& currstring){
    stack <char>st;
    for(int i=0;i<currstring.length();i++){
        if(currstring[i]=='(') st.push('(');
         else if(currstring[i]==')' && st.size()>0) st.pop();
        else if(st.empty()) return false;
    }
    return st.empty();
}


void solve(string& currstring,int n,vector<string>&ans){
    if(currstring.size()==2*n ){
        if(isvalid(currstring)){ ans.push_back(currstring);}
        return ;
    }
    currstring.push_back(')');
    solve(currstring,n, ans);
    currstring.pop_back();
    currstring.push_back('(');
    solve(currstring,n,ans);
      currstring.pop_back();
    


}

    vector<string> generateParenthesis(int n) {
        if(n==1) return {"()"};
        string currstring;
        vector<string>ans;
        
        solve(currstring,n,ans);
        return ans;

        
    }
};