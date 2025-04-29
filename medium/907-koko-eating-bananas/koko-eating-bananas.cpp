class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high =*max_element(piles.begin(),piles.end());
      

        while(low<high){
            int mid=low+(high-low)/2;
            int temp=0;
            for(int i=0;i<piles.size();i++){
                temp+=(  (piles[i]+mid-1)/mid);

            }
            if(temp<=h) high=mid;
          else   
           
           {
            low=mid+1;
           
           }
        }
return low;

        
    }
};