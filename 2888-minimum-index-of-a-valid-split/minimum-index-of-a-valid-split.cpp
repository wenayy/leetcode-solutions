class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp;
         
       
        int n=nums.size();
        for(auto x:nums){
            mp[x]++;

        }
       
        int ans=-1;
        int dominant=0;
        for(auto x:mp){
            if(x.second*2>n ){ dominant=x.first; break;}
        }
        cout<<dominant;
        
 int size1=0;
 int size2=0;
int temp=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==dominant){
                mp[nums[i]]--;    size1=i+1; temp++;  
             size2=(n-i-1);
             
           if ((temp*2 > (size1) ) && (mp[dominant]*2 > (size2))) { 
    ans=i;  break;
}
 

             }

            
            

        }

     if(ans>=0) return ans;
     return -1;
     
    }
};