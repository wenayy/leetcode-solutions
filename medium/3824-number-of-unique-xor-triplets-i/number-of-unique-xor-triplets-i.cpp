class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return n;

        // Find the Most Significant Bit
        int cnt = 0;
        int temp = n;
        while(temp > 0){
            cnt++;
            temp >>= 1;
            
        }
        
        return pow(2, cnt);
    }
};