class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end()) ;
        if(temp==nums) return nums.size();
        int max=nums[0]
;
 
int count=0;
int n=nums.size();
vector<int>modified(n,nums[0]);
for(int i=1;i<nums.size();i++){
    if(nums[i]>max) {max=nums[i]; modified[i]=nums[i];} 
    else modified[i]=max;

     
}
for(int x=0;x<n;x++){
   if (nums[x] ==modified[x]) count++;
}
      


return count;

        
    }
};