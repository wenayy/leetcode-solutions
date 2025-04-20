class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        unordered_map<int,bool>mp; // to track revisits

        long long ans = 0;
        long long  i = 0;

        while ( i>=0 && i < n && !mp[i]) {
           mp[i] = true;

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
 