class Solution {
public:
    int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1; // Min is in the right half
        } else {
            right = mid; // Min is in the left half (including mid)
        }
    }
    return nums[left]; // Or nums[right], since left == right
}
};