class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        l = 0 #starting index
        counter: dict[str, int] = defaultdict(int)
        for r in range (len(s)):
            counter[s[r]] += 
            #Remove the leftmost character from the window, then move the window’s left edge one position right.
            while counter[s[r]] > 1:
                counter[s[l]] -=1
                l += 1
            longest = max(longest, r-l+1)
        return longest
