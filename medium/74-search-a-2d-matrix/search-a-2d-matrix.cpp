class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> merged;
          
       
    
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        merged.push_back(matrix[i][j]);
    }
}
        int i=0;
        cout<<merged.size();
        int j= m*n-1;
        while(i<=j){
           
            int mid=i+((j-i)/2);
            if(merged[mid]==target) return true;
            else if(merged[mid]<target) i=mid+1;
            else j=mid-1;
        }

        return false;
        
    }
};