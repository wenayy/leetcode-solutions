class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return n;

        // Find the Most Significant Bit
        
        int temp = n;
     int cnt = floor(log(temp)/log(2))+1;
        return pow(2, cnt);
    }
};