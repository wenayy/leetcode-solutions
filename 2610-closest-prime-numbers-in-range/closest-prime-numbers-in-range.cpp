#include <iostream>  
#include <vector>  
#include <climits>  // For INT_MAX  

using namespace std;  

class Solution {  
public:  
    vector<int> closestPrimes(int left, int right) {  
        if (right - left + 1 < 2) return {-1, -1}; // added to handle small input ranges  

        vector<bool> isPrime(right + 1, true);  
        vector<int> primes;  

        // Sieve of Eratosthenes  
        isPrime[0] = false;  
        isPrime[1] = false;  

        for (int p = 2; p * p <= right; ++p) {  // Corrected loop condition to 'right'  
            if (isPrime[p]) {  
                for (int i = p * p; i <= right; i += p) {  
                    isPrime[i] = false;  
                }  
            }  
        }  

        // Collect primes within the range [left, right]  
        for (int p = left; p <= right; ++p) { // Changed loop to iterate from left to right.  
            if (isPrime[p]) {  
                primes.push_back(p);  
            }  
        }  

        // Find the closest pair  
        if (primes.size() < 2) return {-1, -1};  // No pair exists  

        int minDiff = INT_MAX;  
        vector<int> result = {-1, -1};  

        for (size_t i = 1; i < primes.size(); ++i) {  
            int diff = primes[i] - primes[i - 1];  
            if (diff < minDiff) {  
                minDiff = diff;  
                result = {primes[i - 1], primes[i]};  
            }  
        }  

        return result;  
    }  
};  