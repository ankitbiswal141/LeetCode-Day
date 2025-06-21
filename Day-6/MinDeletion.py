def minimumDeletions(word: str, k: int) -> int:
    freq =  * 26
    for ch in word:
        freq[ord(ch) - ord('a')] += 1
    freq.sort()

    i = 0
    while i < 26 and freq[i] == 0:
        i += 1

    ans = float('inf')
    for idx in range(i, 26):
        x = freq[idx]
        ops = 0
        for j in range(i, 26):
            y = freq[j]
            if y == 0:
                continue
            if y - x > k:
                ops += y - x - k
            elif y < x:
                ops += y
        ans = min(ans, ops)
    return ans

word = "aabbcc"
k = 1
print("Minimum deletions:", minimumDeletions(word, k))