class Solution {
public:
 

bool canRepairInTime(vector<int>& ranks, int cars, long long T) {
    long long total_cars = 0;
    for (int r : ranks) {
        total_cars += sqrt(T / r); // max cars this mechanic can fix in T minutes
        if (total_cars >= cars) return true;
    }
    return false;
}

long long  repairCars(vector<int>& ranks, int cars) {
    long long left = 1, right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (canRepairInTime(ranks, cars, mid)) right = mid;
        else left = mid + 1;
    }
    return left;
}

};