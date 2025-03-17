class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        vector<int>increasing(n,1);
        
        vector<int>decreasing(n,1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]) decreasing[i]=decreasing[i-1]+1;
            else continue;
        }  
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) increasing[i]=increasing[i+1]+1;
            else continue;
        } 
        for(int i=0;i<n;i++){
            cout<<decreasing[i] ;
        }  
         for(int i=0;i<n;i++){
            cout<<increasing[i] ;
        }  

        for(int j = k; j <= n - k - 1; j++) {
    if (increasing[j+1] >= k && decreasing[j-1] >= k) {
        ans.push_back(j);
    }
}

        
        return ans;  

        
        
    }
};