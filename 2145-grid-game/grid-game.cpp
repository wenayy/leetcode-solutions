class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
vector<long long>prefix1(n,0);
vector<long long>prefix2(n,0);
        long long p1=grid[0][0];
        long long  p2=grid[1][0];
         prefix1[0]=p1;
          prefix2[0]=p2;
for(int i=1;i<n;i++){
    prefix1[i] = prefix1[i - 1] + grid[0][i];
    prefix2[i] = prefix2[i - 1] + grid[1][i];
}

        long long ans=LONG_LONG_MAX;
        for(int i=0;i<n;i++){
            long long rem=prefix1[n-1]- prefix1[i];
           long long rem2 = (i == 0) ? 0 : prefix2[i - 1];

          long long temp =max(rem,rem2);
          ans=min(temp,ans);

        }
        return ans;
    }
};