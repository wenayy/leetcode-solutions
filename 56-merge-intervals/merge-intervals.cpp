class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int k=ans.back()[1];
            int m=intervals[i][0];
            int n=intervals[i][1];
            if(m<=k) ans.back()[1]=max(n,k);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};