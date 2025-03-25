class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int  k=1;int count=0;
       
        for(auto x:nums){
            if(x==0) { count++;}
          else  k*=x;
        }
        vector<int>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(count>1)  return ans;
            if(nums[i]!=0&& count>0) {ans[i]=0;}
            else if( (count  ==0 )&&(nums[i]!=0 )) {ans[i]=k/nums[i] ;}
            else if(count>0 && nums[i]==0) ans[i]=k;
        }
        return ans;
    }
};