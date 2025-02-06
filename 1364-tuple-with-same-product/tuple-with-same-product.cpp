class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
         
        int n= nums.size();
        int ans=0;
      unordered_map<int,int>pair;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pair [nums[i]*nums[j]]++;
            }
        }
         
        for(auto x:pair){
            int result=((x.second)*(x.second-1))/2;
            ans+=result*8;

        }
        return ans;
        

    }
};