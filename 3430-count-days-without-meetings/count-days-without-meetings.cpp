#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days; // No meetings → all days are free

        // Step 1: Sort meetings by start day
        sort(meetings.begin(), meetings.end());

        // Step 2: Merge overlapping/adjacent meetings
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);

        for (int i = 1; i < meetings.size(); i++) {
            int last_end = merged.back()[1];
            int curr_start = meetings[i][0];
            int curr_end = meetings[i][1];

            if (curr_start <= last_end + 1) {
                // Overlapping or adjacent → merge
                merged.back()[1] = max(last_end, curr_end);
            } else {
                // No overlap → add to merged
                merged.push_back(meetings[i]);
            }
        }

        // Step 3: Count free days
        int free_days = 0;

        // Free days before the first meeting
        free_days += max(0, merged[0][0] - 1);

        // Free days between meetings
        for (int i = 1; i < merged.size(); i++) {
            int prev_end = merged[i-1][1];
            int curr_start = merged[i][0];
            free_days += max(0, curr_start - prev_end - 1);
        }

        // Free days after the last meeting
        free_days += max(0, days - merged.back()[1]);

        return free_days;
    }
};