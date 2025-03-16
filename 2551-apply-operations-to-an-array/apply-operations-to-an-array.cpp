class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                nums[i-1]*=2;
                nums[i]=0;
            }
        }
        int n=nums.size();
        vector<int>ans(n,0);
        int i=0;
        for(auto x:nums){
            if(x!=0) {ans[i]=x; i++;}
        }
        return ans;
    }
};