class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.length()==0) return {};
        if(s.length()==1) return {1};
        int n=s.length();
unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()) mp[s[i]]={mp[s[i]].first,i};
           else  mp[s[i]]={i,i};
        }
        vector<pair<int,int>>intervals;
        for(auto [x,y]:mp){
            intervals.push_back(y);
        }
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>merged;
        merged.push_back({intervals[0].first,intervals[0].second});
        for(int i=1;i<intervals.size();i++){
            int k=merged.back().second;
            int m=intervals[i].first;
            int r=intervals[i].second;
            if(m<=k) {merged.back().second=max(k,r); merged.back().first=min(m,merged.back().first);}

            else merged.push_back({intervals[i].first,intervals[i].second})
;        }

vector<int>ans;
for(int i=0;i<merged.size();i++)
{
    int r=merged[i].second;
    int q=merged[i].first;
    int temp= r-q+1;
    ans.push_back(temp);
}
         return ans;
         
 
    }
};