class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int k : queries) {
            int val = nums[k];
            auto &idxs = mp[val];

            if (idxs.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            auto pos = lower_bound(idxs.begin(), idxs.end(), k);
            int ind = pos - idxs.begin();

            int res = INT_MAX;

            if (ind > 0)
                res = min(res, k - idxs[ind - 1]);

            if (ind < idxs.size() - 1)
                res = min(res, idxs[ind + 1] - k);

            // circular case
            res = min(res, n - abs(k - idxs[0]));
            res = min(res, n - abs(k - idxs.back()));

            ans.push_back(res);
        }

        return ans;
    }
};