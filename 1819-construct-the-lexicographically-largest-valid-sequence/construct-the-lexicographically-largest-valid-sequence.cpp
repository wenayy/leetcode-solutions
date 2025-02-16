class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        // The final sequence has length 2*n - 1
        vector<int> result(2*n - 1, 0);
        
        // used[i] = true means we've already placed the number i
        vector<bool> used(n + 1, false);
        
        // Start backtracking from index 0
        backtrack(0, result, used, n);
        
        return result;
    }
    
private:
    bool backtrack(int idx, vector<int>& result, vector<bool>& used, int n) {
        // If we've reached the end, we have a complete valid sequence
        if (idx == (int)result.size()) {
            return true;
        }
        
        // If this position is already occupied, skip it
        if (result[idx] != 0) {
            return backtrack(idx + 1, result, used, n);
        }
        
        // Try placing the largest unused number first
        for (int i = n; i >= 2; i--) {
            if (!used[i]) {
                int secondIdx = idx + i;  // The position for the second occurrence
                
                // Check if secondIdx is within bounds and both spots are free
                if (secondIdx < (int)result.size() && result[idx] == 0 && result[secondIdx] == 0) {
                    // Place i in both positions
                    result[idx] = i;
                    result[secondIdx] = i;
                    used[i] = true;
                    
                    // Recurse to fill the rest
                    if (backtrack(idx + 1, result, used, n)) {
                        return true;
                    }
                    
                    // Backtrack if this path didn't lead to a solution
                    result[idx] = 0;
                    result[secondIdx] = 0;
                    used[i] = false;
                }
            }
        }
        
        // If no larger number fits, try placing 1 (only needs one spot)
        if (!used[1]) {
            result[idx] = 1;
            used[1] = true;
            
            if (backtrack(idx + 1, result, used, n)) {
                return true;
            }
            
            // Backtrack
            result[idx] = 0;
            used[1] = false;
        }
        
        // If nothing worked, return false
        return false;
    }
};
