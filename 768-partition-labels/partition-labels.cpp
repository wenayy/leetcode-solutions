#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurrence;
        for (int i = 0; i < s.size(); ++i) {
            lastOccurrence[s[i]] = i;
        }
        
        vector<int> result;
        stack<int> partitionEnds;
        int start = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (partitionEnds.empty()) {
                partitionEnds.push(lastOccurrence[s[i]]);
            } else {
                if (i > partitionEnds.top()) {
                    // Current character starts a new partition
                    result.push_back(partitionEnds.top() - start + 1);
                    start = i;
                    partitionEnds.push(lastOccurrence[s[i]]);
                } else {
                    // Extend the current partition if necessary
                    if (lastOccurrence[s[i]] > partitionEnds.top()) {
                        partitionEnds.pop();
                        partitionEnds.push(lastOccurrence[s[i]]);
                    }
                }
            }
        }
        
        // Add the last partition
        if (!partitionEnds.empty()) {
            result.push_back(partitionEnds.top() - start + 1);
        }
        
        return result;
    }
};