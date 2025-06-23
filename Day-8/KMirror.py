def to_base_k(num: int, k: int) -> str:
    res = ''
    while num > 0:
        res = str(num % k) + res
        num //= k
    return res

def is_palindrome(s: str) -> bool:
    return s == s[::-1]

def generate_palindromes(length: int):
    res = []
    half_len = (length + 1) // 2
    start = 10 ** (half_len - 1)
    end = 10 ** half_len

    for i in range(start, end):
        first_half = str(i)
        second_half = first_half[:-1] if length % 2 else first_half
        res.append(int(first_half + second_half[::-1]))
    return res

def k_mirror(k: int, n: int) -> int:
    count = 0
    total = 0
    length = 1

    while count < n:
        for num in generate_palindromes(length):
            if is_palindrome(to_base_k(num, k)):
                total += num
                count += 1
                if count == n:
                    return total
        length += 1
    return total

print(k_mirror(2, 20))  # Example
