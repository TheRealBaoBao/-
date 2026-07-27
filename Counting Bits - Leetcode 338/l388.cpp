#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // i & (i - 1) removes the lowest set bit
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};
