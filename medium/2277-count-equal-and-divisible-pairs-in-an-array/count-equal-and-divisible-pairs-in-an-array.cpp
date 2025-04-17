class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;
        for (auto& [val, idxList] : mp) {
            unordered_map<int, int> remFreq;

            // Step 1: Count remainders mod k
            for (int i : idxList) {
                remFreq[i % k]++;
            }

            // Step 2: For each pair of remainders
            for (auto& [r1, c1] : remFreq) {
                for (auto& [r2, c2] : remFreq) {
                    if ((r1 * r2) % k == 0) {
                        if (r1 == r2) {
                            ans += (c1 * (c1 - 1)) / 2; // Choose 2 from c1
                        } else if (r1 < r2) {
                            ans += c1 * c2; // Unique pairs
                        }
                    }
                }
            }
        }

        return ans;
    }
};
