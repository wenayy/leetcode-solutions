class Solution {
public:
    long long coloredCells(int n) {
     long long  ans=5;
        if(n==1) return 1;
        if(n==2) return 5;
        for(int i=3;i<=n;i++){
 ans= ans+4*i-4 ;
        }
        return ans;
      
    }
};