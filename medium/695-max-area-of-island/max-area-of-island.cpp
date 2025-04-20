class Solution {
public:
int m,n;
vector<pair<int,int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
int bfs(vector<vector<int>>&grid,int i, int j, int count){
    queue<pair<int,int>>q;
    grid[i][j]=0;
    q.push({i,j});
     while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(auto r:directions){
            int ni=x+r.first;
            int nj=y+r.second;
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                count++;
                grid[ni][nj]=0;
                q.push({ni,nj});
            }
        }
     }
     return count;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                 int count=   bfs(grid,i,j,1);
                 ans=max(count,ans);
                }
            }
        }
        return ans;
        
    }
};