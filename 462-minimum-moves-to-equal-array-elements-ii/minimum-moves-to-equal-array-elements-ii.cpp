class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int median= nums[nums.size()/2];
        for(auto x:nums){
            ans+=abs(x-median);
        }
        return ans;
       
    }
};