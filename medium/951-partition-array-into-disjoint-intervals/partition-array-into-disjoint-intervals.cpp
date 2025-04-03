class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n= nums.size();
        vector<int>left(n,nums[0]);
        vector<int>right(n,nums[n-1]);
        for(int i=1;i<n;i++){
            left[i]=max(nums[i-1],left[i-1]);
            right[n-i-1]=min(right[n-i],nums[n-i]);


        }
        int  ans=1;
int i=1;
        
           for(int i=0;i<n-1;i++){
            if(left[i]<=right[i])  return i+1;
           
             
           }
            

      

         return -1;



        
    }
};