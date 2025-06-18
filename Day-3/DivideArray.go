package main

import (
	"fmt"
	"sort"
)

func divideArray(nums []int, k int) [][]int {
	// Sort the array to easily group numbers that are close together
	sort.Ints(nums)

	// Initialize the result array
	var result [][]int
	n := len(nums)

	// Form groups of 3 and check if the difference condition is met
	for i := 0; i < n; i += 3 {
		// Check if the difference between the max and min value is <= k
		if nums[i+2]-nums[i] > k {
			// If difference condition fails, return an empty array
			return [][]int{}
		}

		// Add the valid sub-array to the result
		result = append(result, []int{nums[i], nums[i+1], nums[i+2]})
	}

	return result
}

func main() {
	// Test cases
}
