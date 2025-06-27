package main

import (
	"fmt"
	"strings"
)

func isRepeatedSubsequence(s string, seq string, k int) bool {
	pos := 0
	for i := 0; i < k; i++ {
		for _, c := range seq {
			idx := strings.IndexByte(s[pos:], byte(c))
			if idx == -1 {
				return false
			}
			pos += idx + 1
		}
	}
	return true
}

func longestSubsequenceRepeatedK(s string, k int) string {
	freq := make([]int, 26)
	for _, c := range s {
		freq[c-'a']++
	}

	var availableChars []rune
	for c := 'a'; c <= 'z'; c++ {
		if freq[c-'a'] >= k {
			availableChars = append(availableChars, c)
		}
	}

	result := ""
	queue := []string{""}

	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]

		for _, c := range availableChars {
			next := curr + string(c)

			if isRepeatedSubsequence(s, next, k) {
				if len(next) > len(result) || (len(next) == len(result) && next > result) {
					result = next
				}
				queue = append(queue, next)
			}
		}
	}

	return result
}

func main() {
	fmt.Println(longestSubsequenceRepeatedK("letslets", 2)) // Output: "lets"
}