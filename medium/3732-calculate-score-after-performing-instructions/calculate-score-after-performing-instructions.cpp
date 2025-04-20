class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        vector<bool> visited(n, false); // to track revisits

        long long ans = 0;
        int i = 0;

        while (i >= 0 && i < n && !visited[i]) {
            visited[i] = true;

            if (instructions[i] == "add") {
                ans += values[i];
                i += 1;
            } else if (instructions[i] == "jump") {
                i += values[i]; // jump to new index
            }
        }

        return ans;
    }
};
 