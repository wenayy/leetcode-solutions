class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0); // Stores frequency of each character
        int left = 0, maxFreq = 0, maxLen = 0;
        
        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;  
            maxFreq = max(maxFreq, freq[s[right] - 'A']); // Update max frequency

            // If window size - maxFreq > k, then shrink window
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;  
                left++;  
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};