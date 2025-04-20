class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(auto x:answers){
            mp[x]++;
        }
        int ans=0;
        for(auto x:mp){
            
             int max=x.first+1;
             if (x.first==0) ans+=x.second;
           else   if(x.second-max>0){
            if(x.second%max!=0){
               ans += (max * (x.second / (max)) +max  );  }
               else ans+=(max*(x.second/max));


              }
             else   ans+=max;
            
            
             
          

        }
        
        return ans;
    }
};