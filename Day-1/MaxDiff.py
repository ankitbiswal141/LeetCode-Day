def maximumDifference(nums):
    min_value = nums[0]  # First element as the minimum value
    max_difference = -1  # Set max_difference to -1 (indicating no valid pair)

    for j in range(1, len(nums)):
        if nums[j] > min_value:
            # Update with the maximum difference
            max_difference = max(max_difference, nums[j] - min_value)
        # Update with minimum of the current value and nums[j]
        min_value = min(min_value, nums[j])

    return max_difference

