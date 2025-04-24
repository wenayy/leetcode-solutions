class Solution {
public:
int atmostk(vector<int>&nums,int k){
     int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        multiset<int>ms;
        unordered_map<char,int>mp;
        for(auto x:nums){
            if(x&1) mp['o']++;
            else mp['e']++;
        }
      
        int count=0;
        while(i<n){
            ms.insert(nums[i]);
             
            if(nums[i]&1) {count++; mp['o']--;}
           while(count>k){
             
           
               if(nums[j]&1) count--;
             
         
             
            j++;
           }
           ans+=(i-j+1);
           i++;

        }
        return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
       

        return (atmostk(nums,k)-atmostk(nums,k-1));
        
    }
};