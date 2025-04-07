#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd, we cannot split it equally
        if (total_sum % 2 != 0) return false;

        int target = total_sum / 2;
        int n = nums.size();

        vector<bool> dp(target + 1, false);
        dp[0] = true; // base case: sum 0 is always possible with empty subset

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};