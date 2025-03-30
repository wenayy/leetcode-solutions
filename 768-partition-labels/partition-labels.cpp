#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Step 1: Record first and last occurrence of each character
        map<char, pair<int, int>> intervals;
        for (int i = 0; i < s.size(); i++) {
            if (intervals.find(s[i]) == intervals.end()) {
                intervals[s[i]] = {i, i}; // First occurrence
            } else {
                intervals[s[i]].second = i; // Update last occurrence
            }
        }
        
        // Step 2: Extract all intervals and sort by start time
        vector<pair<int, int>> merged;
        for (auto& [c, interval] : intervals) {
            merged.push_back(interval);
        }
        sort(merged.begin(), merged.end());
        
        // Step 3: Merge overlapping intervals
        vector<pair<int, int>> result;
        for (auto& interval : merged) {
            if (result.empty() || interval.first > result.back().second) {
                result.push_back(interval);
            } else {
                result.back().second = max(result.back().second, interval.second);
            }
        }
        
        // Step 4: Calculate partition lengths
        vector<int> partition_sizes;
        for (auto& [start, end] : result) {
            partition_sizes.push_back(end - start + 1);
        }
        
        return partition_sizes;
    }
};