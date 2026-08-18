class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.length();
        int twoBack = 1; // corresponds to dp[i-2]
        int oneBack = 1; // corresponds to dp[i-1]
        
        for (int i = 1; i < n; ++i) {
            int current = 0;
            
            // Single digit check
            if (s[i] != '0') {
                current += oneBack;
            }
            
            // Two digit check
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += twoBack;
            }
            
            twoBack = oneBack;
            oneBack = current;
        }
        
        return oneBack;
    }
};
