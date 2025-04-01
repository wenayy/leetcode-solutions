class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       long long ans=accumulate(nums.begin(),nums.end(),0LL);
        long long a=nums[0];
        int result=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(a>=ans-a)result++;
           a= a+nums[i];
        }
        return result;
        
    }
};