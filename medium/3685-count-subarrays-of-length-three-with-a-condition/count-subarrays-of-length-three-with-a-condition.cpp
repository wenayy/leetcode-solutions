class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<=nums.size()-3;i++){
            int temp=nums[i]+nums[i+2];
            if(temp==(nums[i+1]/2.0)) ans++;
        }
        return ans;
    }
};