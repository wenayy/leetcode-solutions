class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> answer(n, -1);

        // Store original indices of queries so we can restore order later
        vector<pair<int, int>> q_with_idx;
        for (int i = 0; i < n; i++) {
            q_with_idx.push_back({queries[i], i});
        }

        // Sort queries by value
        sort(q_with_idx.begin(), q_with_idx.end());

        // Sort intervals by their left endpoint
        sort(intervals.begin(), intervals.end());

        // Min-heap: {interval size, right}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        int i = 0;

        for (auto& [query, idx] : q_with_idx) {
            // Add intervals whose left <= query
            while (i < intervals.size() && intervals[i][0] <= query) {
                int l = intervals[i][0], r = intervals[i][1];
                int size = r - l + 1;
                minHeap.push({size, r});
                i++;
            }

            // Remove intervals that don't contain the query
            while (!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }

            // Top of the heap is the smallest interval that contains query
            if (!minHeap.empty()) {
                answer[idx] = minHeap.top().first;
            }
        }

        return answer;
    }
};