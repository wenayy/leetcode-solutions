class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> freq;
    long long ans = 0;
    long long pairCount = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        // Before inserting, existing freq contributes to new pairs
        pairCount += freq[nums[right]];
        freq[nums[right]]++;

        // Try to shrink window from the left while still satisfying the condition
        while (pairCount >= k) {
            // All subarrays starting from left...right are valid
            ans += n - right;

            // Remove nums[left] from window and adjust pair count
            freq[nums[left]]--;
            pairCount -= freq[nums[left]];
            left++;
        }
    }
    return ans;
}

};