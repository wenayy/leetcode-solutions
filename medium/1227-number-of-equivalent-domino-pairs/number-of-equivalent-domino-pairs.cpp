class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        
        // Normalize each domino (make smaller number first)
        for (auto& d : dominoes) {
            if (d[0] > d[1]) swap(d[0], d[1]);
        }

        sort(dominoes.begin(), dominoes.end());
        
        for (int i = 0; i < dominoes.size(); i++) {
            for (int j = i + 1; j < dominoes.size(); j++) {
                if (dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) ans++;
            }
        }
         
        return ans;
    }
};
