class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3){
            if(nums[i+2]-nums[i]<=k){
                vector<int>temp;
                for(int j=i;j<i+3;j++){
                    temp.push_back(nums[j]);

                }
                ans.push_back(temp);
            }
            else return {};
        }
        if(ans.size()!=n/3) return {};
        return ans;
        
    }
};