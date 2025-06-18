function divideArray(nums, k) {
  // Sort the array to easily group close numbers together
  nums.sort((a, b) => a - b);
  let result = [];

  // Form sub-arrays of size 3
  for (let i = 0; i < nums.length; i += 3) {
      // Check if the difference condition is met
      if (nums[i + 2] - nums[i] > k) {
          return [];
      }
      result.push([nums[i], nums[i + 1], nums[i + 2]]);
  }

  return result;
}

// Test cases (Write your own)