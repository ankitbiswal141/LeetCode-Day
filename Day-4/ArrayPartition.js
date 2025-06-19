function arrayPartitionSum(nums) {
  // Sort the array
  nums.sort((a, b) => a - b);
  
  let sum = 0;
  // Add every second element starting from index 0
  for (let i = 0; i < nums.length; i += 2) {
      sum += nums[i];
  }
  
  return sum;
}

// Test cases here
