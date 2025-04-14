class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGain = 0, currentGain = 0, start = 0;
    int n = gas.size();

    for (int i = 0; i < n; ++i) {
        int gain = gas[i] - cost[i];
        totalGain += gain;
        currentGain += gain;

        if (currentGain < 0) {
            // Can't reach the next station, try starting from next one
            start = i + 1;
            currentGain = 0;
        }
    }

    return totalGain >= 0 ? start : -1;
}

};