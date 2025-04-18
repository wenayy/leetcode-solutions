class Solution {
public:
 vector<int>temp;
 unordered_map<int,vector<int>>mp;
    Solution(vector<int>& nums) {
    temp  =nums; 
    for(int i=0;i<temp.size();i++){
        mp[temp[i]].push_back(i);
    }

    }
    
    
    int pick(int target) {
      int k=  mp[target].size();
        int index=rand()%k;
        return mp[target][index];
         

   
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */