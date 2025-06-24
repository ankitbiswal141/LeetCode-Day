function findKDistantIndices(nums, key, k) {
  // Step 1: Identify all positions where nums[i] == key
  let keyIndices = [];
  for (let i = 0; i < nums.length; i++) {
      if (nums[i] === key) {
          keyIndices.push(i);
      }
  }

  // Step 2: Initialize the result set
  let result = new Set();

  // Step 3: For each key index, add all indices within the range of k to the result
  for (let idx of keyIndices) {
      for (let i = Math.max(0, idx - k); i <= Math.min(nums.length - 1, idx + k); i++) {
          result.add(i);
      }
  }

  // Step 4: Convert the set to a sorted array
  let resultList = Array.from(result).sort((a, b) => a - b);
  return resultList;
}

// Test case 1
console.log(findKDistantIndices([3, 4, 9, 1, 3, 9, 5], 9, 1));  // Output: [1, 2, 3, 4, 5, 6]

// Test case 2
console.log(findKDistantIndices([2, 2, 2, 2, 2], 2, 2));  // Output: [0, 1, 2, 3, 4]
