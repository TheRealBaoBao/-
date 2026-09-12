class Solution:
    def combine(self, n: int, k: int) -> list[list[int]]:
        res = []
        
        def backtrack(start: int, curr: list[int]):
            if len(curr) == k:
                res.append(curr.copy())
                return
            
            need = k - len(curr)
            # Optimization: only loop up to n - need + 1
            for i in range(start, n - need + 2):
                curr.append(i)
                backtrack(i + 1, curr)
                curr.pop()
                
        backtrack(1, [])
        return res
