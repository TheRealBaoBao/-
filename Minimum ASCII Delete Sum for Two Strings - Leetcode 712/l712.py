class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        
        # dp[j] will store the maximum ASCII sum of common subsequence 
        # up to index j of s2
        dp = [0] * (n + 1)
        
        for i in range(1, m + 1):
            prev = 0  # Represents dp[i-1][j-1]
            for j in range(1, n + 1):
                temp = dp[j]  # Store current dp[j] before it gets overwritten
                
                if s1[i - 1] == s2[j - 1]:
                    # If characters match, add their ASCII value to the diagonal previous state
                    dp[j] = prev + ord(s1[i - 1])
                else:
                    # Otherwise, take the maximum possible common sum from top or left
                    dp[j] = max(dp[j], dp[j - 1])
                    
                prev = temp
                
        # Total ASCII sum of both strings
        total_sum = sum(ord(c) for c in s1) + sum(ord(c) for c in s2)
        
        # Minimum delete sum = Total sum - 2 * (Max Common Subsequence ASCII Sum)
        return total_sum - 2 * dp[n]
