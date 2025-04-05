class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int>left(n,0);
        vector<int>right(n,nums[n-1]);
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],nums[i-1]);
            right[n-i-1]=max(right[n-i],nums[n-i]);

        }

    int ans=0;
    for(int i=0;i<n;i++){
     int water=min(left[i],right[i])-nums[i];
       if(water>0) ans+=water;
    }
    return ans;

        
    }
};