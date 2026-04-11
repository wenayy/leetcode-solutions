class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        
          int ans =INT_MAX;
       
        unordered_map<int, vector<int>>mp;
//      std::unordered_map<int, std::set<int, std::greater<int>>> mp;
// mp.emplace(m, std::set<int, std::greater<int>>{});  // key m -> empty set
        for (int i=0;i<n;i++){
            
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size()>=3){
                int first = mp[nums[i]][mp[nums[i]].size()-1];
                      // 0 -> 1st, 1 -> 2nd, 2 -> 3rd
                int third = mp[nums[i]][mp[nums[i]].size()-3];
                 
     
      
                 int temp=(first-third);
                 cout<<temp;
                ans=min(ans,temp);
            }
        
            
        }

        
         
        
        return ans==INT_MAX?-1:2*ans;
        
    }
};