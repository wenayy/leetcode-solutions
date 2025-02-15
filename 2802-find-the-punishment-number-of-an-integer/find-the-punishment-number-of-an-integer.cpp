class Solution {
public:
    bool check(string s, int n, int i, int currsum) {
        if (i == s.length()) return currsum == n; // ✅ Ensure all digits are used and sum is correct

        bool possible = false;
        for (int j = i; j < s.length(); j++) {
            int temp = stoi(s.substr(i, j - i + 1)); // Extract number from substring
            
            if (currsum + temp > n) break; // ✅ Early termination optimization

            possible = possible || check(s, n, j + 1, currsum + temp);
            if (possible) return true; // ✅ Stop unnecessary recursion
        }
        return false;
    }

    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            int x = i * i;
            string s = to_string(x);
            if (check(s, i, 0, 0)) result += x; // ✅ Compare to `i`, not `n`
        }
        return result;
    }
};
