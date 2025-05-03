class Solution {
public:
void solve(vector<int>& candidates,int target,int i, vector<int>&temp,vector<vector<int>>&result,int n,int currsum){
    if(i>=n ||(currsum>target) ) return ;
    if( currsum==target){
        result.push_back(temp);
        return ;

    }
    
    temp.push_back(candidates[i]);
    solve(candidates,target,i,temp,result,n,currsum+candidates[i]);
    temp.pop_back();
    solve(candidates,target,i+1,temp,result,n,currsum);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      int n=candidates.size();
      vector<vector<int>>result;
      vector<int>temp;
      solve(candidates,target,0,temp,result,n,0);
      return result;

        
    }
};