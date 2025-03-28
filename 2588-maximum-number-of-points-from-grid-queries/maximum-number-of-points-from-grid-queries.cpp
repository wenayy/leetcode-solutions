class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();
        vector<int> result(k, 0);

        // Directions for moving in 4 directions
        vector<int> dir = {-1, 0, 1, 0, -1};

        // Store (query value, original index)
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < k; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // Min-Heap (value, row, col)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({grid[0][0], {0, 0}});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        
        int count = 0;  // Count of points collected
        int maxValue = 0;  // Max value processed so far

        for (auto &[q, index] : sortedQueries) {
            while (!minHeap.empty() && minHeap.top().first < q) {
                auto [val, cell] = minHeap.top();
                minHeap.pop();
                int r = cell.first, c = cell.second;
                count++;
                maxValue = val;

                // Expand in 4 directions
                for (int d = 0; d < 4; d++) {
                    int nr = r + dir[d], nc = c + dir[d + 1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        minHeap.push({grid[nr][nc], {nr, nc}});
                    }
                }
            }
            result[index] = count; // Store the result for this query
        }

        return result;
    }
};
