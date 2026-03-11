class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        vector<int>count(grid.size());
        for(int i=0;i<grid.size();i++){
            int count1 =0;
            for (int j=grid.size()-1;j>=0;j--){
                if(grid[i][j]==0) count1++;
                else break; 
            }
            count[i]=count1;
        }

        vector<int>required(grid.size());
        for(int i=0;i<grid.size();i++){
            required[i]=grid.size()-i-1;
        }

 
 int n= grid.size();
 int swaps=0;
 for(int i=0;i<n;i++){
    bool found = false;
    for (int j=i;j<n;j++){
        if(count[j]>=required[i])  {
            swaps+=(j-i);
            while(j>i ){
                swap(count[j],count[j-1]);
                j--;
            }
            found = true;
            break;
        }
        
       

    }
     if(!found) return -1;

  

 }
  return swaps;
 

        
      
    }
};