#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2; // Total pairs
        
        unordered_map<int, long long> freq;
        long long goodPairs = 0;
        
        for (int i = 0; i < n; i++) {
            int val = i - nums[i];
            if (freq.count(val)) {
                goodPairs += freq[val]; // Adding previous occurrences of val
            }
            freq[val]++; // Increment count of this value
        }
        
        return totalPairs - goodPairs;
    }
};

 