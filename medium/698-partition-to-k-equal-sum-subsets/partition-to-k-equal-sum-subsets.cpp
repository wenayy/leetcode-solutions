class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % k != 0) return false;
        int target = totalSum / k;

        sort(nums.rbegin(), nums.rend());  // bigger first helps prune faster
        vector<int>bucket(k, 0);

        return backtrack(nums, 0, bucket, target);
    }

    bool backtrack(vector<int>& nums, int idx, vector<int>& bucket, int target) {
        if(idx == nums.size()) {
            for(int b : bucket)
                if(b != target) return false;
            return true;
        }

        for(int i=0;i<bucket.size();i++) {
            if(bucket[i] + nums[idx] > target) continue;

            bucket[i] += nums[idx];
            if(backtrack(nums, idx+1, bucket, target)) return true;
            bucket[i] -= nums[idx];

            // optimization → skip similar empty buckets
            if(bucket[i] == 0) break;
        }

        return false;
    }
};
