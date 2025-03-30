class Solution {
public:
    int longestPalindrome(string s, string t) {
        int max_len = 0;
        
        // Try all possible substrings of s (including empty)
        for (int i = 0; i <= s.length(); i++) {
            for (int j = i; j <= s.length(); j++) {
                string sub_s = s.substr(i, j - i);
                
                // Try all possible substrings of t (including empty)
                for (int k = 0; k <= t.length(); k++) {
                    for (int l = k; l <= t.length(); l++) {
                        string sub_t = t.substr(k, l - k);
                        
                        // Concatenate and check if palindrome
                        string combined = sub_s + sub_t;
                        if (isPalindrome(combined)) {
                            max_len = max(max_len, (int)combined.length());
                        }
                    }
                }
            }
        }
        
        return max_len;
    }
    
private:
    bool isPalindrome(const string &s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};