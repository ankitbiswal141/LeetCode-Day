function maximumDifference(nums) {
  let minValue = nums[0];  // First element as the minimum value
  let maxDifference = -1;  // Set maxDifference to -1 (indicating no valid pair)

  for (let j = 1; j < nums.length; j++) {
      if (nums[j] > minValue) {
          // Update with the largest difference
          maxDifference = Math.max(maxDifference, nums[j] - minValue);
      }
      // Update to the minimum of the current value and nums[j]
      minValue = Math.min(minValue, nums[j]);
  }

  return maxDifference;
}
