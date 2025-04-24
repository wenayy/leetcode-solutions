class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> mp(nums.begin(), nums.end()); // total distinct
        multiset<int> ms;
        set<int> ms2;

        int i = 0, j = 0, n = nums.size(), ans = 0;

        while (i < n) {
            ms.insert(nums[i]);
            ms2.insert(nums[i]);

            if (ms2.size() == mp.size()) {
                ans += n - i;

                while (  ms2.size() == mp.size()) {
                    // Erase one instance from multiset
                    ms.erase(ms.find(nums[j]));

                    // Check if that value still exists in multiset
                    if (ms.find(nums[j]) == ms.end()) {
                        ms2.erase(nums[j]);
                    }

                    j++;
                    if (ms2.size() == mp.size()) {
                        ans += n - i;
                    }
                }
            }

            i++;
        }

        return ans;
    }
};
