class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
       const int MOD=1e9+7;
        for (int i=0;i<queries.size();i++){
            int l=queries[i][0];
            while(l<nums.size() && l<=queries[i][1]){
               nums[l] =(1LL*nums[l]*queries[i][3])%MOD;
               
                l+=queries[i][2];

            }
        }
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
      ans^=nums[i];
        }
        return ans;
        
    }
};