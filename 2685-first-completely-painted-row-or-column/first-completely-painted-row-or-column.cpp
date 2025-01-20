class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
           int m=mat.size();
           int n=mat[0].size();
           unordered_map<int,pair<int,int>>temp;
           for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp[mat[i][j]]={i,j};
            }
           }
           vector<int>rows(m,0);
           vector<int>cols(n,0);
           for(int i=0;i<arr.size();i++){
            auto [row,col]=temp[arr[i]];
            rows[row]++;
            cols[col]++;
            if(rows[row]==n|| cols[col]==m) return i;
           }
         return -1;   
    }
};