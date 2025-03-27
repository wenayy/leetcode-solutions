class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;  // If digit < 9, just increment and return
                return digits;
            }
            digits[i] = 0;  // If digit is 9, set it to 0 and continue
        }
        
        // If all digits were 9, we need an extra leading 1 (e.g., 999 -> 1000)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
