class Solution {
public:
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int ans = nums[0];
    int maxProd = nums[0];
    int minProd = nums[0];

    for (int i = 1; i < n; ++i) {
        int curr = nums[i];

        if (curr < 0)
            swap(maxProd, minProd); // flip min/max when curr is negative

        maxProd = max(curr, maxProd * curr);
        minProd = min(curr, minProd * curr);

        ans = max(ans, maxProd);
    }

    return ans;
}

};