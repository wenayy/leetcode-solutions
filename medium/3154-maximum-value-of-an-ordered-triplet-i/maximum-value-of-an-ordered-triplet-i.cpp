class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
    long long ans=INT_MIN;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
             
                long long r=nums[k];
                  long long  temp= (nums[i]-nums[j])*r;
                ans=max(temp , ans);
            }
        }
    }
     
    return max(0LL,ans);
    }
};