class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Step 1: Add all servers (1's in the grid) to the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        int count = 0; // Count of communicating servers

        // Step 2: BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (visited[x][y]) continue; // Skip if already visited
            visited[x][y] = true;

            // Increment the count only if it's not a standalone server
            bool isCommunicating = false;

            // Check all servers in the same row
            for (int j = 0; j < n; j++) {
                if (j != y && grid[x][j] == 1) {
                    isCommunicating = true;
                    if (!visited[x][j]) q.push({x, j});
                }
            }

            // Check all servers in the same column
            for (int i = 0; i < m; i++) {
                if (i != x && grid[i][y] == 1) {
                    isCommunicating = true;
                    if (!visited[i][y]) q.push({i, y});
                }
            }

            // Only count the server if it's part of a communication group
            if (isCommunicating) count++;
        }

        return count;
    }
};
