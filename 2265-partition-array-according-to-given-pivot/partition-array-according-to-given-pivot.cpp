class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller, equal, greater;

        // Step 1: Partition elements into three separate arrays
        for (int num : nums) {
            if (num < pivot) 
                smaller.push_back(num);
            else if (num == pivot) 
                equal.push_back(num);
            else 
                greater.push_back(num);
        }

        // Step 2: Combine partitions
        smaller.insert(smaller.end(), equal.begin(), equal.end());
        smaller.insert(smaller.end(), greater.begin(), greater.end());

        return smaller;
    }
};
