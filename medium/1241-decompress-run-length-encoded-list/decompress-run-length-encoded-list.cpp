class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i+=2){
            int freq=nums[i];
            int val=nums[i+1];
            vector<int>temp(freq,val );
            ans.insert(ans.end(),temp.begin(),temp.end()) ;
          
        }
return ans; 

        
    }
};