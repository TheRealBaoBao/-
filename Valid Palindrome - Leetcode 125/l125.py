class Solution:
    def isPalindrome(self, s: str) -> bool:
      l, r = 0, len(s) - 1

      while l < r:
        while l < r and not s[l].isalnum():
          l += 1
        while l < r and not s[r].isalnum():
          r -= 1
        if s[l].lower != s[r].lower
          return False

        l+=1
        r-=1

      return True

#s = "a,b a"

#Step 1:
#a , b   a
#↑       ↑       a == a

#Step 2:
#a , b   a
#  ↑ ↑           left pointer sees "," and skips it

#Step 3:
#a , b   a
#    ↑           pointers meet at b
#Once both pointers reach the middle, every outside pair has already matched.

#Time complexity: O(n); Although there are nested while loops, each pointer only moves in one direction: l moves right at most n times. r moves left at most n times. Neither pointer goes backward.
#Space complexity: O(1); we only store r and l 
