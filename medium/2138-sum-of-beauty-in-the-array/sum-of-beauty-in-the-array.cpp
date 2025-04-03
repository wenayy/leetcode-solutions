class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>left (n, 0);
             vector<int>right (n,nums[n-1]); // because min compare karna hai so min(0, 3) = 0; y ho jaayega which iwll give wrong answer 
        for(int i=1;i<n;i++){
            
           left[i]=max(left[i-1],nums[i-1]);
         right[n-i-1]=min(right[n-i],nums[n-i]); // min because if min se hi bada hoga toh baankiyon se toh bada hoga hi,


        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(left[i]<nums[i] && right[i]>nums[i])  ans+=2;
            else  if(nums[i-1]<nums[i] && nums[i]<nums[i+1]) ans+=1;
           
        }

        
        return ans; 
        
    }
};