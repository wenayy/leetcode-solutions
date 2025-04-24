class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> distinctSet(nums.begin(), nums.end());
        int totalDistinct = distinctSet.size();

        unordered_map<int, int> freq;
        int ans = 0;
        int j = 0;

        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;

            while (freq.size() == totalDistinct) {
                ans += n - i;  // All subarrays from i to n-1 are valid
                freq[nums[j]]--;
                if (freq[nums[j]] == 0) {
                    freq.erase(nums[j]);
                }
                j++;
            }
        }

        return ans;
    }
};
