class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
       
        for(int i=0;i<s.length();i++){
            if( isalnum(s[i])) ans+=tolower(s[i]);
        
        }
      int n=ans.length();
      cout<<ans;
       int i=0,j=n-1;
       while(i<j){
        if(ans[i]!=ans[j]) return false;
        i++; j--;
       }
       return true;
    }
};