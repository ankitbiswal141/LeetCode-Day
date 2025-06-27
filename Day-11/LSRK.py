from collections import deque

def is_repeated_subsequence(s: str, seq: str, k: int) -> bool:
    pos = 0
    for _ in range(k):
        for ch in seq:
            pos = s.find(ch, pos)
            if pos == -1:
                return False
            pos += 1
    return True

def longest_subsequence_repeated_k(s: str, k: int) -> str:
    # Count character frequency
    freq = [0] * 26
    for ch in s:
        freq[ord(ch) - ord('a')] += 1

    # Characters that appear at least k times
    available_chars = [chr(i + ord('a')) for i in range(26) if freq[i] >= k]

    result = ""
    queue = deque([""])

    while queue:
        curr = queue.popleft()

        for ch in available_chars:
            new_seq = curr + ch

            if is_repeated_subsequence(s, new_seq, k):
                if len(new_seq) > len(result) or (len(new_seq) == len(result) and new_seq > result):
                    result = new_seq
                queue.append(new_seq)

    return result

# Example usage
print(longest_subsequence_repeated_k("letslets", 2))  # Output: "lets"