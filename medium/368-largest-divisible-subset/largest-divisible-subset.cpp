class Solution {
public:
   #include <vector>
#include <algorithm>

 

vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.empty()) return {};
    
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] = size of largest subset ending with nums[i]
    vector<int> parent(n, -1); // parent[i] = index of previous element in the subset
    
    int max_size = 1;
    int max_index = 0;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > max_size) {
            max_size = dp[i];
            max_index = i;
        }
    }
    
    vector<int> result;
    while (max_index != -1) {
        result.push_back(nums[max_index]);
        max_index = parent[max_index];
    }
    
    return result;
}
};