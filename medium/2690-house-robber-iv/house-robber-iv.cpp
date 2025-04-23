class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int lower=*min_element(nums.begin(),nums.end());
        int higher=*max_element(nums.begin(),nums.end());
        int ans=higher;
       
            while(lower<=higher){
                 int mid=lower+(higher-lower)/2;
                int count=0;
                for(int i=0;i<nums.size();i++){
                    if(nums[i]<=mid){ count++; i++; }
                }
                if(count>=k){ ans=min(ans,mid); higher=mid-1;}
                else lower=mid+1;

            }
            return  ans ;
        
        

        
    }
};