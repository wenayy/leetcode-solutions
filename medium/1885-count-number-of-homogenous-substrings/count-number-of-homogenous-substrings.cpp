class Solution {
public:
    int countHomogenous(string s) {
    int n = s.length();
    int j = 0;
    int i = 0;
    long long ans = 0;
    int mod = 1e9 + 7;

    while (i < n) {
        unordered_map<char, int> mp;  // reset map for each homogenous block

        while (i < n && s[i] == s[j]) {
            mp[s[i]]++;
            ans = (ans + mp[s[i]]) % mod;
            i++;
        }

        j = i;
    }

    return ans;
}



};