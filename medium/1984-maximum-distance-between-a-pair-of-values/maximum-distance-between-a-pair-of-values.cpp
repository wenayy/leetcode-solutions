class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int ans = 0;

        for(int i = 0; i < n; i++) {
            auto it = upper_bound(nums2.begin() + i, nums2.end(), nums1[i], greater<int>());
            
            int j = (it - nums2.begin()) - 1;  
            
            if(j >= i)
                ans = max(ans, j - i);
        }

        return ans;
    }
};