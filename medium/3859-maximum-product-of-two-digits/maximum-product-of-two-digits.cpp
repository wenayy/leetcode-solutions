class Solution {
public:
    int maxProduct(int n) {
        vector<int>nums;
        while(n>0){
            int temp=n%10;
            nums.push_back(temp);
            n=n/10;
        }
        sort(nums.begin(),nums.end());
        int k=nums.size();
    return (nums[k-1]*nums[k-2]);
        
    }
};