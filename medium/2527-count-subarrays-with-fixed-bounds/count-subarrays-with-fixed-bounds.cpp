class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int lastMin = -1, lastMax = -1, badIdx = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                badIdx = i;
            }
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }

            ans += max(0, min(lastMin, lastMax) - badIdx);
        }

        return ans;
    }
};

