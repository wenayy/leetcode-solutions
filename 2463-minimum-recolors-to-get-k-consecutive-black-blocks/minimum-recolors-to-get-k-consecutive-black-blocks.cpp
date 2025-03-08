class Solution {
public:
    int minimumRecolors(string blocks, int k) {
       set<int>ans;
        int m=0;
      
        for(int i=0;i<=blocks.length()-k;i++){
            
              int temp=0;
            for(int j=i;j<i+k;j++){
                 
                  if(blocks[j]=='W') {++temp;}
                 
                 
            }
            if(temp==0) ans.insert(0);
            else ans.insert(temp);
         
           
            
           

            
            

        }
       
         
        return *ans.begin();
    }
};