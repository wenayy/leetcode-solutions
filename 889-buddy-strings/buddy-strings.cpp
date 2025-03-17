class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length(), m = goal.length();
        if (n != m) return false;  // Lengths must be equal

        if (s == goal) {
            unordered_map<char, int> freq;
            for (char c : s) freq[c]++;
            for (auto it : freq) {
                if (it.second >= 2) return true;  // Check for duplicate characters
            }
            return false;  // No duplicate characters, cannot swap
        }

        vector<int> diff;
        for (int i = 0; i < n; i++) {
            if (s[i] != goal[i]) diff.push_back(i);
        }

        if (diff.size() != 2) return false;  // Must have exactly 2 mismatches
        swap(s[diff[0]], s[diff[1]]);  // Try swapping the mismatched characters
        return s == goal;
    }
};
