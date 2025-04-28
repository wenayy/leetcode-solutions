class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long ans = 0;
        long long sum = 0;
        long long j = 0;
        
        for(long long i = 0; i < n; i++){
            sum += nums[i];
            
            while(sum * (i - j + 1) >= k){
                sum -= nums[j];
                j++;
            }
            
            ans += (i - j + 1); // number of valid subarrays ending at i
        }
        
        return ans;
    }
};
