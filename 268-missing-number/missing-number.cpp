class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
         vector<int>temp(n+1);
         sort(nums.begin(),nums.end());
         iota(temp.begin(),temp.end(),0);
         for(int i=0;i<n;i++){
            int ans=nums[i]^temp[i];
            if(ans!=0) return temp[i];
         }
         return n;

    }
};