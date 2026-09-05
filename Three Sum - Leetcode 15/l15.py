def threeSum(nums: list[int]) -> list[list[int]]:
    # Sort the array to easily handle duplicates and use two pointers
    nums.sort()
    result = []
    
    for i in range(len(nums) - 2):
        # Optimization: If the current number is positive, 
        # it's impossible to sum to 0 with subsequent numbers.
        if nums[i] > 0:
            break
            
        # Skip duplicate values for the first element
        if i > 0 and nums[i] == nums[i - 1]:
            continue
            
        # Set up two pointers
        left = i + 1
        right = len(nums) - 1
        
        while left < right:
            current_sum = nums[i] + nums[left] + nums[right]
            
            if current_sum == 0:
                result.append([nums[i], nums[left], nums[right]])
                
                # Move pointers and skip duplicates for left and right
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                    
                left += 1
                right -= 1
                
            elif current_sum < 0:
                # Sum is too small, move left pointer to increase sum
                left += 1
            else:
                # Sum is too large, move right pointer to decrease sum
                right -= 1
                
    return result
