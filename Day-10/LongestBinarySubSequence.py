def longestSubsequence(s: str, k: int) -> int:
    length = 0
    value = 0

    for i in reversed(range(len(s))):
        if s[i] == '0':
            length += 1
        else:
            if length < 30 and (value | (1 << length)) <= k:
                value |= (1 << length)
                length += 1

    return length