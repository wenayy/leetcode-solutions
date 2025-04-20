class Solution {
public:
  vector<pair<int,int>>directions={{-1,0},{0,1},{1,0},{0,-1}};
  int m,n;
  void dfs(vector<vector<char>>&grid,int i,int j){
   if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
    grid[i][j]='0';
    for(auto x:directions){
        int ni=i+x.first;
        int nj=j+x.second;
        dfs(grid,ni,nj);
    }

    



  }
    int numIslands(vector<vector<char>>& grid) {
         m=grid.size();
      n=grid[0].size();
        int ans=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1') {
                ans++;
            dfs(grid,i,j);
            }
        }
      }

        return ans;
        
        
        
    }
};