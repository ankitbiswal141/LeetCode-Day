package main

import (
	"fmt"
	"math"
)

func maxDistance(s string, k int) int {
	maxDist := 0

	// Helper function to calculate max distance for a chosen dominant direction pair
	calc := func(a, b byte) int {
		cnt := 0
		mx := 0
		ans := 0
		for i := 0; i < len(s); i++ {
			if s[i] == a || s[i] == b {
				mx += 1
			} else if cnt < k {
				mx += 1
				cnt += 1
			} else {
				mx -= 1
			}
			if mx > ans {
				ans = mx
			}
		}
		return ans
	}

	// Try all four directional combinations
	dist1 := calc('S', 'E') // South and East
	dist2 := calc('S', 'W') // South and West
	dist3 := calc('N', 'E') // North and East
	dist4 := calc('N', 'W') // North and West

	maxDist = int(math.Max(float64(maxDist), math.Max(math.Max(float64(dist1), float64(dist2)), math.Max(float64(dist3), float64(dist4)))))

	return maxDist
}

func main() {
	s := "NWSE"
	k := 1
	fmt.Println("Maximum Manhattan Distance:", maxDistance(s, k)) // Output: 3
}