class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>>matrix(n,vector<int>(n,0));
        for(int i=0;i<queries.size();i++){
            int m=queries[i][0];
            int n=queries[i][1];
            int r=queries[i][2];
            int s=queries[i][3];
            for(int j=m;j<=r;j++){
                for(int k=n;k<=s;k++){
                    matrix[j][k]++;
                }
            }

        }
        return matrix;
    }
};