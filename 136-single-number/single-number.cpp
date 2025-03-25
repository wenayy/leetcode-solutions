class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k=0;
        for(auto x:nums){
            k^=x;
        }
        return k;
    }
};