class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals by start
        sort(intervals.begin(), intervals.end());

        // Pair each query with its index to restore order later
        vector<pair<int, int>> queryWithIndex;
        for (int i = 0; i < queries.size(); ++i) {
            queryWithIndex.push_back({queries[i], i});
        }

        // Sort queries
        sort(queryWithIndex.begin(), queryWithIndex.end());

        // Min heap to store {size, end}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<int> result(queries.size(), -1);

        int i = 0; // Pointer for intervals
        for (auto& [query, idx] : queryWithIndex) {
            // Push intervals that start <= query
           while (i < intervals.size() && intervals[i][0] <= query) {
    minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
    ++i;
}

// Now pop invalid ones
while (!minHeap.empty() && minHeap.top().second < query) {
    minHeap.pop();
}

            if (!minHeap.empty()) {
                result[idx] = minHeap.top().first; // size of smallest interval covering query
            }
        }

        return result;
    }
};
