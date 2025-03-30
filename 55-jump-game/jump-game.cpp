class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) return true;
        vector<vector<int>>intervals;
        for(int i=0;i<nums.size();i++){
            intervals.push_back({i,nums[i]+i});
            

        }
     

        vector<vector<int>>merged;
        merged.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int k=merged.back()[1];
            int m=intervals[i][0];
            int n=intervals[i][1];
            if(m<=k) 
           { merged.back()[1]=max(n,k); merged.back()[0]=min(merged.back()[0],m);}
           else{
            merged.push_back(intervals[i]);
           }


        }
    
 
       if(merged.size()>=2) return false;
     else  return true;
    

      
    }
};