class Solution {
public:
    bool check(vector<int>& nums) {
        int max=0;
        int n=nums.size();
        for(int i=1;i<nums.size();i++){
             if(nums[i]<nums[i-1]) max++;
            
             

        }
if(nums[0]<nums[n-1]) max++;
        
        return (max<=1);
    }
};