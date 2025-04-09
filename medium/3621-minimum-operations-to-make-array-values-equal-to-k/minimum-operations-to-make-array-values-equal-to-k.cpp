class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
      unordered_map<int,int>mp;
       
       int n=nums.size();
       for(int i=0;i<n;i++){
      mp[nums[i]]++;
       }
       int r=*min_element(nums.begin(),nums.end());

       if(n==1 && nums[0]!=k && nums[0]<k) return -1;
        
        if(  n==1 &&nums[0]<k ) return -1;
      else  if(n==1 && nums[0]==k) return 0;
             if(k>r && n>1) return -1;
             if(k<r  ) return mp.size();
       
     else return mp.size()-1;
        
    }
};