class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        """
        Find the minimum possible difference between max and min values
        after adding a value x (where -k <= x <= k) to each element.
      
        Args:
            nums: List of integers
            k: Maximum absolute value that can be added to each element
          
        Returns:
            Minimum possible difference between max and min after operations
        """
        # Find the maximum and minimum values in the original array
        max_value = max(nums)
        min_value = min(nums)
      
        # Calculate the minimum possible difference
        # The best strategy is to decrease max_value by k and increase min_value by k
        # This gives us a potential difference of (max_value - min_value - 2*k)
        # If this difference is negative, it means we can make all values equal (return 0)
        min_difference = max_value - min_value - 2 * k
      
        # Return 0 if we can make all values equal, otherwise return the minimum difference
        return max(0, min_difference)
