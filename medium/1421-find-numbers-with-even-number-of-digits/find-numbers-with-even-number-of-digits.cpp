class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
         for(auto x:nums){
            int temp=0;
            while(x>0){
                 

               x= x/10;
                temp++;
               
              
            }
            if(!(temp&1)) ans++;
         }
        return ans;
        
    }
};