def divideString(s, k, fill):
    return [s[i:i + k].ljust(k, fill) for i in range(0, len(s), k)]