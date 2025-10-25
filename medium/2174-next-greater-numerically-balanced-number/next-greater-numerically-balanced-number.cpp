class Solution {
public:
    // return true if x is 'beautiful' by the definition:
    // every digit d that appears must appear exactly d times.
    bool isBeautiful(int x) {
        string s = to_string(x);
        vector<int> cnt(10, 0);
        for (char c : s) cnt[c - '0']++;

        // If '0' appears at all, impossible (0 != count>0)
        if (cnt[0] > 0) return false;

        // For digits 1..9: if they appear, they must appear exactly digit times.
        for (int d = 1; d <= 9; ++d) {
            if (cnt[d] > 0 && cnt[d] != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int x = n + 1;
        // Brute-force forward until we find one.
        // (For typical problem constraints this is fine.)
        while (true) {
            if (isBeautiful(x)) return x;
            ++x;
        }
        // unreachable
        return -1;
    }
};
