class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) ans+=nums[i];
            else break;
        }
 
        auto it=find(nums.begin(),nums.end(),ans);
        if(it==nums.end()) return ans;
        if(it!=nums.end())  {
       
         
         while(find(nums.begin(),nums.end(),ans)!=nums.end()) {ans++;}}

 
         return ans;
      


        
    }
};