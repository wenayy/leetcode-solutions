class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mp;
        int n = nums.size();
        vector<int> ans(n - k + 1);  // Correct size for result array
        int j = k, r = 0;  // `j` starts at k, `r` is left pointer

        // Insert first k elements into multiset
        for (int i = 0; i < k; i++) {
            mp.insert(nums[i]);
        }
        ans[0] = *mp.rbegin();  // Max of the first window

        // Start sliding the window
        while (j < n) {
            mp.erase(mp.find(nums[r]));  // Remove element going out of window
            r++;  // Move left pointer
            mp.insert(nums[j]);  // Insert new element coming into window
            ans[r] = *mp.rbegin();  // Store max value
            j++;  // Move right pointer
        }

        return ans;
    }
};
