class Solution {
public:
    int mirrorDistance(int n) {
        int original = n;
        long long rev = 0;

        while(n > 0){
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }

        return abs(original - rev);
    }
};