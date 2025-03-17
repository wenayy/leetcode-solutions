class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0; // Count the number of modifications needed
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                count++;
                if (count > 1) return false;  // More than one modification needed → return false
                
                // Fixing the issue by modifying nums[i-1] or nums[i]
                if (i - 2 >= 0 && nums[i - 2] > nums[i]) {
                    nums[i] = nums[i - 1]; // Modify nums[i] to be nums[i-1]
                } else {
                    nums[i - 1] = nums[i]; // Modify nums[i-1] to be nums[i]
                }
            }
        }
        
        return true;
    }
};
