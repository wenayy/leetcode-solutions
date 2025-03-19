class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int swap=0;
        for(int i=0;i<=n-3;i++){
            if(nums[i]==0){
                nums[i+1]^=1;
                nums[i+2]^=1;
                nums[i]^=1;
                swap++;
            }
            else continue;


        }
    if(nums[n-1]==nums[n-2]&& nums[n-1]==1) return swap;
    return -1;
    }
};