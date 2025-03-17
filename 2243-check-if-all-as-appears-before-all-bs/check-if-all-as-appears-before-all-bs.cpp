class Solution {
public:
    bool checkString(string s) {
         int n=s.length();
        vector<int>a,b;
        for(int i=0;i<s.length();i++){
  for(int j=i+1;j<n;j++){
    if(s[j]=='a' && s[j-1]=='b' ) return false;
     
  }

        }
         return true;
    }
};