class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, nums[0]);
        vector<int> right(n, 0);  // ✅ Initialize right with 0
        
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], nums[i-1]);
        }

        right[n-1] = nums[n-1]; // ✅ Initialize correctly
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], nums[i+1]); // ✅ Fix index issue
        }

        long long ans = 0;
        for(int i=1; i<n-1; i++){
            ans = max(((left[i] - nums[i]) * (long long)(right[i])), ans);
        }
        return ans;
    }
};
