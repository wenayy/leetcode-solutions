class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int i=0;
        int temp=0;
        
        while(i<n){
            temp+=nums[i];
            ans=max(temp,ans);
            cout<<ans<<endl;
            if(temp<0) temp=0;
            
             
            i++;


        }
        return ans;
        
    }
};