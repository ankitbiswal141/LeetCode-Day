package main

import (
	"fmt"
	"strconv"
)

func toBaseK(num, k int64) string {
	if num == 0 {
		return "0"
	}
	res := ""
	for num > 0 {
		res = strconv.FormatInt(num%k, 10) + res
		num /= k
	}
	return res
}

func isPalindrome(s string) bool {
	l, r := 0, len(s)-1
	for l < r {
		if s[l] != s[r] {
			return false
		}
		l++
		r--
	}
	return true
}

func generatePalindromes(length int) []int64 {
	res := []int64{}
	halfLen := (length + 1) / 2
	start := int64(1)
	for i := 1; i < halfLen; i++ {
		start *= 10
	}
	end := start * 10

	for i := start; i < end; i++ {
		s := strconv.FormatInt(i, 10)
		rs := s
		if length%2 == 1 {
			rs = s[:len(s)-1]
		}
		for j := len(rs) - 1; j >= 0; j-- {
			s += string(rs[j])
		}
		val, _ := strconv.ParseInt(s, 10, 64)
		res = append(res, val)
	}
	return res
}

func kMirror(k int, n int) int64 {
	var sum int64 = 0
	count := 0
	length := 1

	for count < n {
		pals := generatePalindromes(length)
		for _, val := range pals {
			if isPalindrome(toBaseK(val, int64(k))) {
				sum += val
				count++
				if count == n {
					return sum
				}
			}
		}
		length++
	}
	return sum
}

func main() {
	fmt.Println(kMirror(2, 20))  // Example
}
