class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  // Important!

        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        long long temp = 1;

        while (i < n) {
            temp *= nums[i];

            while (temp >= k) {
                temp /= nums[j];
                j++;
            }

            ans += (i - j + 1);
            i++;
        }

        return ans;
    }
};
