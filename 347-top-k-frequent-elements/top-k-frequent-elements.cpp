class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
         
        for(auto x:nums){
            mp[x]++;
                    }
                    vector<pair<int,int>>ans;
                    for(auto x:mp){
                        ans.emplace_back(x.second,x.first);
                        
                    }
                    vector<int>result;
                    sort(ans.rbegin(),ans.rend());
                    for(int i=0;i<k;i++){
                        result.push_back(ans[i].second);

                    }
                    return result;
                   
    }
};