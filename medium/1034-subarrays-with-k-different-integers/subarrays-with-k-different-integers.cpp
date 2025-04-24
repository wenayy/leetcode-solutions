class Solution {
public:
int atmostK(vector<int>&nums,int k){
    int n=nums.size();
       multiset<int>ms;
       set<int>s;
       int i=0,j=0;
       int ans=0;
       while(i<nums.size()){
        ms.insert(nums[i]);
        s.insert(nums[i]);
        while(s.size()>k){
            ms.erase(ms.find(nums[j]));
            if(ms.find(nums[j]) ==ms.end()){
                s.erase(nums[j]);

            }
            j++;
        }
        ans+=(i-j+1);
        i++;

       }
       return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       

return atmostK(nums,k)-atmostK(nums,k-1);


    }
};
