class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;  // Map value to its index
        }
        
        int maxLen = 0;
        unordered_map<int, int> dp;  // dp[i][j] = length of sequence ending with arr[i], arr[j]
        
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                int prev = arr[j] - arr[i];
                if (prev < arr[i] && index.count(prev)) {
                    int k = index[prev];
                    int len = dp.count(k * n + i) ? dp[k * n + i] + 1 : 3;
                    dp[i * n + j] = len;
                    maxLen = max(maxLen, len);
                }
            }
        }
        
        return maxLen >= 3 ? maxLen : 0;
    }
};