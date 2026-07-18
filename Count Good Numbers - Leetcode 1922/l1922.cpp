#include <iostream>

class Solution {
public:
    long long MOD = 1e9 + 7;

    // Helper function to calculate (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base = base % MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long odd_count = n / 2;
        long long even_count = (n + 1) / 2;

        // At even indices: 5 choices (0, 2, 4, 6, 8)
        // At odd indices: 4 choices (2, 3, 5, 7)
        long long ans1 = power(5, even_count);
        long long ans2 = power(4, odd_count);

        return (ans1 * ans2) % MOD;
    }
