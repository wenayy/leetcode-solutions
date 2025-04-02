class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>mp;
     
        int n=nums.size();
           vector<int>ans(n-k+1);
        int j=k;
        int r=0;

        for(int i=0;i<k;i++){
            mp.insert(nums[i]);

        }
        ans[0]=*mp.rbegin();

        while(j<n){
            mp.erase(mp.find(nums[r])); 
            r+=1;
             
            
            mp.insert(nums[j]);
             j+=1;
           

            ans[r]= *mp.rbegin();





        }
        return ans;
        
    }
};