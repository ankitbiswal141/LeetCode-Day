package main

import (
	"fmt"
	"math"
)

func maximumDifference(nums []int) int {
	minValue := nums[0]  // First element as the minimum value
	maxDifference := -1  // Set maxDifference to -1 (indicating no valid pair)

	for j := 1; j < len(nums); j++ {
		if nums[j] > minValue {
			// Update with the larger difference
			maxDifference = int(math.Max(float64(maxDifference), float64(nums[j]-minValue)))
		}
		// Update with minimum of the current value and nums[j]
		minValue = int(math.Min(float64(minValue), float64(nums[j])))
	}

	return maxDifference
}

func main() {
	// Test cases
}
