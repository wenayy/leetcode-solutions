class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<=nums.size()-3;i++){
            int temp=nums[i]+nums[i+2];
            cout<<temp<<nums[i+1]<<endl;
            if(temp==(double(nums[i+1])/2)) ans++;
        }
        return ans;
    }
};