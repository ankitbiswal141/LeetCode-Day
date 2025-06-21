package main

import (
	"fmt"
	"sort"
)

func minimumDeletions(word string, k int) int {
	freq := make([]int, 26)
	for _, ch := range word {
		freq[ch-'a']++
	}
	sort.Ints(freq)

	i := 0
	for i < 26 && freq[i] == 0 {
		i++
	}

	ans := 1 << 30
	for ; i < 26; i++ {
		x := freq[i]
		ops := 0
		for j := i; j < 26; j++ {
			y := freq[j]
			if y == 0 {
				continue
			}
			if y-x > k {
				ops += y - x - k
			} else if y < x {
				ops += y
			}
		}
		if ops < ans {
			ans = ops
		}
	}
	return ans
}

func main() {
	word := "aabbcc"
	k := 1
	fmt.Println("Minimum deletions:", minimumDeletions(word, k))
}