class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(auto x:answers){
            mp[x]++;
        }
        int ans=0;
        for(auto x:mp){
            
             int mx=x.first+1;
             if (x.first==0) ans+=x.second;
         
           
            else   {  ans += mx * ((x.second + mx - 1) / mx);  }
              


             
      
            
            
             
          

        }
        
        return ans;
    }
};