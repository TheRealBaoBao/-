#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int numSquares(int n) {
        // dp[i] will store the least number of perfect squares that sum to i
        std::vector<int> dp(n + 1, INT_MAX);
        
        // Base case: 0 requires 0 perfect squares
        dp[0] = 0;
        
        // Fill the dp table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
        
        return dp[n];
    }
};
