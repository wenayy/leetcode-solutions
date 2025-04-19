class Solution {
public:
    int countKDifference(const vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            // Check nums[i] + k
            if (mp.count(a + k)) {
                for (int j : mp[a + k]) {
                    if (j > i) ans++;
                }
            }
            // Check nums[i] - k
            if (mp.count(a - k)) {
                for (int j : mp[a - k]) {
                    if (j > i) ans++;
                }
            }
        }

        return ans;
    }
};
