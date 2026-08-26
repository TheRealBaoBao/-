#hashmap best as we want to track which numbers we've seen before and look them up instantly

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #create empty hash map to store each number we see along the index so we can quickly look it up
        num_to_index = {}

        #loop through the array using enumerate
        for i, num in enumerate(nums):
            complement = target - num #the num needed to hit the target

            if complement in num_to_index: #check hashmap
                return [num_to_index[complement], i]
            
            num_to_index[num] = i #store the current number in the map if we haven't seen the complement

#O(n) time complexity from for loop, O(n) space complexity from hash map

#Walkthrough for nums = [2, 7, 11, 15], target = 9:

#Current number	Needed complement	Hash map before check	Result
#2	7	{}	Store 2: 0
#7	2	{2: 0}	Found 2, return [0, 1]
