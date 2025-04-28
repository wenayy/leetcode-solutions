class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int temp = 0;

        for (int i = 0; i < n; i++) {
            temp = max(temp + nums[i], nums[i]);  // extend or start new
            ans = max(ans, temp);  // update answer
        }

        return ans;
    }
};
