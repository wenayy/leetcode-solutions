class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
       
        int temp=0;
          unordered_map<long long ,long long>mp;
          mp[0] = 1;
        long long  ans=0;
        for(int i=0;i<n;i++){
             
           if(nums[i]%modulo==k) temp++;
          long long  r=temp%modulo;
          long long  count= ( r-k+modulo)%modulo;
           ans+=mp[count];
           mp[r]++;
        }
       
         

return ans;
        
    }
};