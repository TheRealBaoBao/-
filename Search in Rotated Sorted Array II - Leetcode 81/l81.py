def search(nums: list[int], target: int) -> bool:
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        # Found the target
        if nums[mid] == target:
            return True
        
        # Trickiest case: handling duplicates where left, mid, and right are equal.
        # We cannot determine which side is sorted, so we shrink both ends.
        if nums[left] == nums[mid] == nums[right]:
            left += 1
            right -= 1
            
        # Left half is sorted
        elif nums[left] <= nums[mid]:
            # Check if target lies within the sorted left half
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
                
        # Right half is sorted
        else:
            # Check if target lies within the sorted right half
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1
                
    return False
