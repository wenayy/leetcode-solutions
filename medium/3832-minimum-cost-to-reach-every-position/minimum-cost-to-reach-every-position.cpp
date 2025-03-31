class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n=cost.size();
        vector<int>ans(n);
        ans[0]=cost[0];
        int mn=ans[0];
        for(int i=1;i<n;i++){
           mn=min(cost[i],mn);
           ans[i]=mn;
        }
        return ans;
        
        
    }
};