package main

import (
	"fmt"
	"sort"
)

func findKDistantIndices(nums []int, key, k int) []int {
	// Step 1: Identify all positions where nums[i] == key
	var keyIndices []int
	for i, num := range nums {
		if num == key {
			keyIndices = append(keyIndices, i)
		}
	}

	// Step 2: Initialize the result set
	result := make(map[int]struct{})

	// Step 3: For each key index, add all indices within the range of k to the result
	for _, idx := range keyIndices {
		for i := max(0, idx-k); i <= min(len(nums)-1, idx+k); i++ {
			result[i] = struct{}{}
		}
	}

	// Step 4: Convert the set to a slice
	var resultList []int
	for key := range result {
		resultList = append(resultList, key)
	}

	// Step 5: Sort the result
	sort.Ints(resultList)
	return resultList
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Test case 1
	nums1 := []int{3, 4, 9, 1, 3, 9, 5}
	key1, k1 := 9, 1
	fmt.Println(findKDistantIndices(nums1, key1, k1)) // Output: [1, 2, 3, 4, 5, 6]

	// Test case 2
	nums2 := []int{2, 2, 2, 2, 2}
	key2, k2 := 2, 2
	fmt.Println(findKDistantIndices(nums2, key2, k2)) // Output: [0, 1, 2, 3, 4]
}
