def divide_array(nums, k):
    # Sort the array to group close numbers together
    nums.sort()
    result = []
    
    # Form sub-arrays of size 3
    for i in range(0, len(nums), 3):
        # Check if the difference condition is met
        if nums[i+2] - nums[i] > k:
            return []
        result.append([nums[i], nums[i+1], nums[i+2]])
    
    return result

# Test Cases (Write your own test cases)