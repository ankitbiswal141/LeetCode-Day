def findKDistantIndices(nums, key, k):
    # Step 1: Identify all positions where nums[i] == key
    key_indices = [i for i, num in enumerate(nums) if num == key]
    
    # Step 2: Initialize the result set
    result = set()
    
    # Step 3: For each key index, add all indices within the range of k to the result
    for idx in key_indices:
        for i in range(max(0, idx - k), min(len(nums), idx + k + 1)):
            result.add(i)
    
    # Step 4: Convert the set to a sorted list and return it
    return sorted(result)

# Test case 1
print(findKDistantIndices([3, 4, 9, 1, 3, 9, 5], 9, 1))  # Output: [1, 2, 3, 4, 5, 6]

# Test case 2
print(findKDistantIndices([2, 2, 2, 2, 2], 2, 2))  # Output: [0, 1, 2, 3, 4]
