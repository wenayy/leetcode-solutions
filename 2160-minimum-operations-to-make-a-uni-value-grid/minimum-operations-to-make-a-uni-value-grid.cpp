class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>all;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                all.push_back(grid[i][j]);
            }
        }
        sort(all.begin(),all.end());
        int rem=all[0]%x;
        for(auto r:all){
            if(r%x!=rem) return -1;
        }
        int ans=0;

        int median=all[all.size()/2];
        for(auto y:all){
            ans+=abs(median-y)/x;
        }
return ans;
    }
};