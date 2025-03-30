#include <queue>
#include <vector>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for (int num : nums) {
            if (min_heap.size() < k) {
                min_heap.push(num);
            } else if (num > min_heap.top()) {
                min_heap.pop();
                min_heap.push(num);
            }
        }
        
        return min_heap.top();
    }
};