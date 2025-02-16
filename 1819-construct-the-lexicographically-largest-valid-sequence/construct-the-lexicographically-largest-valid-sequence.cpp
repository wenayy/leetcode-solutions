class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        // The final sequence has length 2*n - 1
        vector<int> result(2*n - 1, 0);

        // Track which indices are already occupied
        vector<bool> usedPositions(2*n - 1, false);

        // Track which numbers 1..n are used
        vector<bool> usedNumbers(n + 1, false);

        // Start backtracking from index 0
        backtrack(0, result, usedPositions, usedNumbers, n);

        return result;
    }

private:
    bool backtrack(int idx,
                   vector<int>& result,
                   vector<bool>& usedPositions,
                   vector<bool>& usedNumbers,
                   int n)
    {
        // If we've filled all indices, we're done
        if (idx == (int)result.size()) {
            return true;
        }

        // If this position is already occupied, move to the next
        if (usedPositions[idx]) {
            return backtrack(idx + 1, result, usedPositions, usedNumbers, n);
        }

        // Try to place numbers from n down to 2 for a lexicographically largest result
        for (int i = n; i >= 2; i--) {
            if (!usedNumbers[i]) {
                int j = idx + i;
                // Check if j is in range and both idx and j are free
                if (j < (int)result.size() &&
                    !usedPositions[j])
                {
                    // Place i at both positions
                    result[idx] = i;
                    result[j]  = i;
                    usedPositions[idx] = true;
                    usedPositions[j]   = true;
                    usedNumbers[i]     = true;

                    // Recurse
                    if (backtrack(idx + 1, result, usedPositions, usedNumbers, n)) {
                        return true;
                    }

                    // Backtrack
                    result[idx] = 0;
                    result[j]   = 0;
                    usedPositions[idx] = false;
                    usedPositions[j]   = false;
                    usedNumbers[i]     = false;
                }
            }
        }

        // If no larger number could be placed, try to place 1
        // (1 only needs a single position)
        if (!usedNumbers[1]) {
            result[idx] = 1;
            usedPositions[idx] = true;
            usedNumbers[1] = true;

            if (backtrack(idx + 1, result, usedPositions, usedNumbers, n)) {
                return true;
            }

            // Backtrack
            result[idx] = 0;
            usedPositions[idx] = false;
            usedNumbers[1] = false;
        }

        // If nothing fits here, return false
        return false;
    }
};
