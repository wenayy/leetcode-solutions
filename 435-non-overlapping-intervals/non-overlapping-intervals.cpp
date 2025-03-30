class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        vector<vector<int>>checking;
        sort(intervals.begin(),intervals.end());
        checking.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int k=checking.back()[1];
            int m=intervals[i][0];
            if(k>m) {ans++; checking.back()[1]=min(k,intervals[i][1]);}
            else checking.push_back(intervals[i]);
        }
         
        return ans;
    }
};