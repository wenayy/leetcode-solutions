class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
int n=nums.size();
        int ans=0;
        vector<int>prefix(n);
        prefix[0]=nums[0];
       // if(prefix[0]%k==0) ans+=1;
        
        for(int i=1;i<n;i++){
//if(nums[i]%k==0) ans+=1;
            prefix[i]=(prefix[i-1]+nums[i]);
        }
        unordered_map<int,int>mp;
        vector<int>modul(n);
        for(int i=0;i<n;i++){
          int rem=prefix[i]%k;
          if(rem<0)   modul[i]=rem+k;
          else   modul[i]=rem;
        }


         
        
        mp[0]=1;
        for(auto x:modul){
           if(mp[x]>0) ans+=mp[x]; 
            mp[x]++;
        }

         
        return ans;
        
    }
};