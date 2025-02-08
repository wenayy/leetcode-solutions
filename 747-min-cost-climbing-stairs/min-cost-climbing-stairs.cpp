class Solution {
public:
    vector<int> dp;

    void initialize(int n) {
        dp.assign(10001, -1);  // ✅ Set size and fill with -1
    }

    int minCost(vector<int>& cost, int i) {
        if (i >= cost.size()) return 0;
        if (dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(minCost(cost, i + 1), minCost(cost, i + 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        initialize(n + 1);  // ✅ Call this before using dp
        return min(minCost(cost, 0), minCost(cost, 1));
    }
};
