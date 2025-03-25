#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        if (rectangles.size() < 3) return false; // Need at least 3 rectangles to split into 3 sections

        // Function to merge intervals
        auto mergeIntervals = [](vector<vector<int>>& intervals) {
            if (intervals.empty()) return intervals;
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> merged;
            merged.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); ++i) {
                if (intervals[i][0] < merged.back()[1]) {
                    merged.back()[1] = max(merged.back()[1], intervals[i][1]);
                } else {
                    merged.push_back(intervals[i]);
                }
            }
            return merged;
        };

        // Extract and merge x intervals (startx, endx)
        vector<vector<int>> xIntervals;
        for (const auto& rect : rectangles) {
            xIntervals.push_back({rect[0], rect[2]});
        }
        vector<vector<int>> mergedX = mergeIntervals(xIntervals);
        if (mergedX.size() >= 3) return true;

        // Extract and merge y intervals (starty, endy)
        vector<vector<int>> yIntervals;
        for (const auto& rect : rectangles) {
            yIntervals.push_back({rect[1], rect[3]});
        }
        vector<vector<int>> mergedY = mergeIntervals(yIntervals);
        if (mergedY.size() >= 3) return true;

        return false;
    }
};