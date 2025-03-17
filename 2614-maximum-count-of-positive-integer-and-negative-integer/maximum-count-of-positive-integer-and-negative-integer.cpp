class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int odd=0;
        int even=0;
        for(auto x:nums){
            if(x<0)  odd++;
            else if (x>0) even++;

        }
        return max(even, odd);
    }
};