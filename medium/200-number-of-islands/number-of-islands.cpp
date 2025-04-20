class Solution {
public:
  vector<pair<int,int>>directions={{-1,0},{0,1},{1,0},{0,-1}};
  int m,n;
  void bfs(vector<vector<char>>&grid,int i,int j){
    queue<pair<int,int>>q;
     grid[i][j]='0';
    q.push({i,j});
   
    while(!q.empty()) { 
        auto [l,y]=q.front();
        q.pop();
    for(auto x:directions){
        int ni=l+x.first;
        int nj=y+x.second;
         if ((ni >= 0 && ni < m )&&(nj >= 0 && nj < n )&& grid[ni][nj] == '1') {
grid[ni][nj]='0';
        q.push({ni,nj});
         }



    }}

    



  }
    int numIslands(vector<vector<char>>& grid) {
         m=grid.size();
      n=grid[0].size();
        int ans=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1') {
                ans++;
            bfs(grid,i,j);
            }
        }
      }

        return ans;
        
        
        
    }
};