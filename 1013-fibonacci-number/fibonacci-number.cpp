class Solution {
public:
 
 
    int fib(int n) {
       
       vector<int>dp(n+1,0);
          if(n<=0) return n;

          dp[0]=0;
          dp[1]=1;
 
       
      for(int j=2;j<n+1;j++){ 
        dp[j]=  dp[j-1]+dp[j-2] ;}
       
        return dp[n];
    }
};