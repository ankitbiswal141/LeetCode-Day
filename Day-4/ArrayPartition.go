package main

import (
	"fmt"
	"sort"
)

func arrayPartition(nums []int) int {
	// Sort the array
	sort.Ints(nums)

	sum := 0
	// Add every second element starting from index 0
	for i := 0; i < len(nums); i += 2 {
		sum += nums[i]
	}

	return sum
}

func main() {
	// Test cases here
}
