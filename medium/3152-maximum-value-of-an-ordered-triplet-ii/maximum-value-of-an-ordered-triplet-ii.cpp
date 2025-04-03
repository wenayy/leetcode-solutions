class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,nums[0]);
        vector<int>right(n,0);
        
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],nums[i-1]);
           right[n-i-1]=max(right[n-i],nums[n-i]);

        }
        long long ans=0;
        for(int i=1;i<n;i++){
            ans=max(((left[i]-nums[i])*(long long)(right[i])),ans);

        }
        return ans;
        
    }
};