import (
	"strings"
)

func divideString(s string, k int, fill rune) []string {
	n := len(s)
	var result []string
	for i := 0; i < n; i += k {
			end := i + k
			if end > n {
					result = append(result, s[i:] + strings.Repeat(string(fill), end - n))
			} else {
					result = append(result, s[i:end])
			}
	}
	return result
}