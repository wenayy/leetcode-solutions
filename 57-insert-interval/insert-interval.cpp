class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         
         sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        
            intervals.push_back(newInterval);
        
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int k=result.back()[1];
            int m=intervals[i][0];
            int l=intervals[i][1];
            if(m<=k) {result.back()[1]=max(k,l);}
            else result.push_back(intervals[i]);
        }
        return result;
        
    }
};