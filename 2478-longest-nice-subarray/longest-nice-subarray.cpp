class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, or_mask = 0, max_len = 1;

        for (int r = 0; r < n; r++) {
            // If nums[r] conflicts with current OR mask, shrink window from left
            while ((or_mask & nums[r]) != 0) {
                or_mask ^= nums[l];  // Remove nums[l] from OR mask
                l++;
            }
            
            or_mask |= nums[r];  // Add nums[r] to OR mask
            max_len = max(max_len, r - l + 1); // Update max length
        }

        return max_len;
    }
};
