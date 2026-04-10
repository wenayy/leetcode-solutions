class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
       
        unordered_map<int,vector<int>>mp;
        for (int i=0;i<n;i++){
            
            mp[nums[i]].push_back(i);
        }
        for(auto x:mp){
            for(int i=0;i<x.second.size();i++){
                cout<<x.second[i];
            }
            cout<<endl;
        }
        int ans=INT_MAX;
        for(int i=0;i<mp.size();i++){
            
            if(mp[i].size()>=3)
            for(int j=0;j<mp[i].size();j++){
                
                for(int k=j+1;k<mp[i].size();k++){
                    int temp1=abs(mp[i][j]-mp[i][k]);
                    for (int l=k+1;l<mp[i].size();l++){
                        int temp2= abs(mp[i][k]-mp[i][l]);
                        int temp3=abs(mp[i][j]-mp[i][l]);
                        ans =min(temp1+temp2+temp3,ans);
                    }
                }
            }
        }

        return ans==INT_MAX?-1:ans;
        
    }
};