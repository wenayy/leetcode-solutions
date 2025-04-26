class Solution {
public:
     int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 2) q.push({i,j});  // push rotten oranges
            if(grid[i][j] == 1) fresh++;         // count fresh oranges
        }
    }

    int minutes = 0;
    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    while(!q.empty() && fresh > 0){
        int sz = q.size();
        for(int i=0; i<sz; i++){
            auto [x,y] = q.front(); q.pop();
            for(auto [dx,dy] : dir){
                int nx = x+dx, ny = y+dy;
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1){
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx,ny});
                }
            }
        }
        minutes++; // after one level (one minute)
    }

    return (fresh == 0) ? minutes : -1;
}

};
