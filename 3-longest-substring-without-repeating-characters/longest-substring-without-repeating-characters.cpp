class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int ans = 0, n = s.length();
        unordered_map<char, int> mp;

        while (j < n) {
            // Increase the count of s[j]
            mp[s[j]]++;

            // If we have a duplicate character, shrink the window
            while (mp[s[j]] > 1) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);  // Remove if count becomes 0
                i++;
            }

            // Update maximum window size
            ans = max(ans, j - i + 1);

            // Move forward
            j++;
        }

        return ans;
    }
};
