class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
      vector<pair<int,int>>sumofdigits ;
      for(int i=0;i<nums.size();i++){
        int sum=0;
        int temp=nums[i];
        while(temp>0){
            sum+=temp%10;
            temp=temp/10;

        }
        sumofdigits.push_back({sum,i});
      } 
      unordered_map<int,vector<int>>mp;
      for(auto x:sumofdigits){
        mp[x.first].push_back(nums[x.second]);

      } 
      int result=-1;
      for(auto x:mp){
        if(x.second.size()>=2) result=max(result,x.second[0]+x.second[1] );
      }
      return result;
    }
};