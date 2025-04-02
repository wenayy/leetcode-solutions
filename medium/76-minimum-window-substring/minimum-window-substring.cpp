class Solution {
public:
    bool isMapEmpty(const unordered_map<char, int>& mp) {
        for (const auto& [key, value] : mp) {
            if (value > 0) return false;  // If any value is positive, we still need it
        }
        return true;  // All required characters are satisfied
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        
        for (char x : t) {
            mp[x]++;  // Count occurrences of each character in t
        }

        int i = 0, j = 0;
        int n = s.length();
        int minLen = INT_MAX, startIdx = 0;  // Track the smallest window
        int required = t.size();  // Total characters needed

        while (j < n) {
            // If s[j] exists in mp, decrease its count
            if (mp.find(s[j]) != mp.end()) {
                if (mp[s[j]] > 0) {
                    required--;  // Decrease required count if it's a needed character
                }
                mp[s[j]]--;
            }

            // When all required characters are found, try shrinking the window
            while (required == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startIdx = i;  // Store the starting index of the minimum window
                }

                // Try removing s[i] from the window
                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) {  // If a needed character is removed, increase required count
                        required++;
                    }
                }
                i++;  // Shrink from the left
            }
            j++;  // Expand window from the right
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};