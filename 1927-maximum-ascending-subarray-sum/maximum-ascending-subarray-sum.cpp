class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        if(nums.size()==1) return nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){ ans+=nums[i-1]; }
            else  {  ans=0;}
            result=max(result,ans+nums[i]);


        }
        return result;
    }
};