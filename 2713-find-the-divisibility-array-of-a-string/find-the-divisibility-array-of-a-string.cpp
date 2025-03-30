class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n=word.length();
      
      long long  k=0;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
                 k= (k*10+(word[i]-'0'))%m;
            if(k==0) ans[i]=1;
            else ans[i]=0;
          
        }
        return ans;
    }
};