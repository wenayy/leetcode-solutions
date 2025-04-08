class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 1; // At least 1 if nums is non-empty

        for (int x : st) { // Iterate over the set to avoid duplicates
            if (st.find(x - 1) == st.end()) { // Check if x is the start of a sequence
                int curr_num = x; // Start counting from x
                int curr_length = 1;

                while (st.find(curr_num + 1) != st.end()) { // Expand the sequence
                    curr_num++;
                    curr_length++;
                }

                ans = max(ans, curr_length); // Update ans after counting the sequence
            }
        }

        return ans;
    }
};