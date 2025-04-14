class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& nums, int i) {
        if (i >= n - 1) return 0; // reached or crossed end
        if (nums[i] == 0) return 1e9; // can't move forward
        if (dp[i] != -1) return dp[i];

        int min_jumps = 1e9;
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < n) {
                min_jumps = min(min_jumps, 1 + solve(nums, i + j));
            }
        }

        return dp[i] = min_jumps;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);
        return solve(nums, 0);
    }
};
