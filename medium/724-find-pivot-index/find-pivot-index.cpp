class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        int prefix=0;

        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            if((sum-prefix+nums[i])==(prefix)) return i;
        }
        return -1;
    }
};