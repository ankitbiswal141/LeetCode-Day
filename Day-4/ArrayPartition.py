def arrayPartition(nums):
    # Sort the array
    nums.sort()

    sum = 0
    # Add every second element starting from index 0
    for i in range(0, len(nums), 2):
        sum += nums[i]

    return sum

# Test cases here
