#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballToColor; // Stores {ball -> color}
        unordered_map<int, int> colorCount;  // Stores {color -> count of balls}
        int distinctColors = 0;
        vector<int> result;

        for (const auto& q : queries) {
            int ball = q[0], color = q[1];

            // If ball already has a color, reduce old color's count
            if (ballToColor.count(ball)) {
                int oldColor = ballToColor[ball];
                if (--colorCount[oldColor] == 0) {
                    colorCount.erase(oldColor); // Remove color if no ball uses it
                    distinctColors--;
                }
            }

            // Assign new color
            ballToColor[ball] = color;

            // Increase color count and update distinctColors
            if (colorCount[color]++ == 0) {
                distinctColors++;
            }

            result.push_back(distinctColors);
        }

        return result;
    }
};
