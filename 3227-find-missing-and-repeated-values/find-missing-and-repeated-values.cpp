class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>a;
        vector<int>b;
        long long temp= n*n;
        long long ans=((temp)*(temp+1))/2;
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(find(a.begin(),a.end(),grid[i][j])!=a.end()){ b.push_back(grid[i][j]); }
else  {a.push_back(grid[i][j]);result+=grid[i][j];}
            }
        }
   b.push_back(ans-result);
    return b;
        
    }
};