package main

func longestSubsequence(s string, k int) int {
	length := 0
	value := 0

	for i := len(s) - 1; i >= 0; i-- {
			if s[i] == '0' {
					length++
			} else {
					if length < 30 && (value|(1<<length)) <= k {
							value |= (1 << length)
							length++
					}
			}
	}

	return length
}