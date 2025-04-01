class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         int n=nums.size();
         int ans=0;
         unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                if(abs(mp[nums[i]]-i)<=k) ans++;
                 
            }
          mp[nums[i]]=i;
              
             
        }
       if (ans==0) return false;
       return true;
        
    }
};