class Solution {
public:
    int countHomogenous(string s) {
    long long ans = 0, count = 1;
    int mod = 1e9 + 7;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            count = 1;
        }
        ans = (ans + count) % mod;
    }

    // Include the first character (which was missed at start)
    return (ans + 1) % mod;
}


};