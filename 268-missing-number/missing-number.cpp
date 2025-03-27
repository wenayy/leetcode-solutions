class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long temp=(n*(n+1))/2;
        int ans=0;
        for(auto x:nums){
            ans+=x;

        }
        return temp-ans;
    }
};