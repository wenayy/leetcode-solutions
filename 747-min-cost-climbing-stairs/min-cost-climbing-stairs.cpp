#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int minCost(vector<int>& cost, int i) {
        if (i >= cost.size()) return 0;  // Base case: beyond the last step
        if (dp[i] != -1) return dp[i];   // Use memoized result
        
        // Choose 1-step or 2-steps
        return dp[i] = cost[i] + min(minCost(cost, i + 1), minCost(cost, i + 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n, -1);  // Initialize memoization array

        // Start from either 0th or 1st step
        return min(minCost(cost, 0), minCost(cost, 1));
    }
};
