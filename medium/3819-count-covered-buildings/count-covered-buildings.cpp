class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rowMap, colMap;
        
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            rowMap[y].push_back(x);
            colMap[x].push_back(y);
        }
        
        // Sort rows and columns
        for (auto& [_, vec] : rowMap) sort(vec.begin(), vec.end());
        for (auto& [_, vec] : colMap) sort(vec.begin(), vec.end());
        
        int ans = 0;
        
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            
            auto& row = rowMap[y];
            auto& col = colMap[x];
            
            bool left = false, right = false, up = false, down = false;
            
            // Binary search in row to find if smaller or greater x exists
            auto it = lower_bound(row.begin(), row.end(), x);
            if (it != row.begin()) left = true; // something smaller exists
            if (next(it) != row.end()) right = true; // something bigger exists
            
            // Binary search in col to find if smaller or greater y exists
            it = lower_bound(col.begin(), col.end(), y);
            if (it != col.begin()) down = true;
            if (next(it) != col.end()) up = true;
            
            if (left && right && up && down) {
                ans++;
            }
        }
        
        return ans;
    }
};
