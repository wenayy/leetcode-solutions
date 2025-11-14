class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>>matrix(n,vector<int>(n,0));
        for(auto x :queries){
            int m=x[0];
            int n=x[1];
            int r=x[2];
            int s=x[3];
            for(int j=m;j<=r;j++){
                for(int k=n;k<=s;k++){
                    matrix[j][k]++;
                }
            }

        }
        return matrix;
    }
};