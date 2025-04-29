class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int mx=*max_element(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int n=nums.size();
        long long count=0;
        long long ans=0;
        while(i<n){
            if(nums[i]==mx) count++;
            while(count==k){
                ans+=(n-i);
                if(nums[j]==mx) count--;
                j++;

            }
            i++;

        }
        return ans;
    }
};