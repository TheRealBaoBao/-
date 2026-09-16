def fairCandySwap(aliceSizes: list[int], bobSizes: list[int]) -> list[int]:
    # Calculate the total candies for Alice and Bob
    sumA = sum(aliceSizes)
    sumB = sum(bobSizes)
    
    # Calculate the target difference
    # y = x + (sumB - sumA) // 2
    delta = (sumB - sumA) // 2
    
    # Convert Bob's sizes to a set for O(1) lookups
    bob_set = set(bobSizes)
    
    # Find the matching pair
    for x in aliceSizes:
        target_y = x + delta
        if target_y in bob_set:
            return [x, target_y]
