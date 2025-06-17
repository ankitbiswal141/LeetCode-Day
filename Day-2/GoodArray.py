MOD = 10**9 + 7
MAX = 100005
fact = [1] * MAX
invFact = [1] * MAX

def mod_pow(base, exp):
    result = 1
    base %= MOD
    while exp > 0:
        if exp % 2:
            result = (result * base) % MOD
        base = (base * base) % MOD
        exp //= 2
    return result

def mod_inverse(a):
    return mod_pow(a, MOD - 2)

def init_factorials():
    for i in range(1, MAX):
        fact[i] = (fact[i - 1] * i) % MOD
    invFact[MAX - 1] = mod_inverse(fact[MAX - 1])
    for i in range(MAX - 2, 0, -1):
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD

def nCk(n, k):
    if k < 0 or k > n:
        return 0
    return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD

def count_good_arrays(n, m, k):
    init_factorials()
    g = n - k
    res = m
    res = (res * mod_pow(m - 1, g - 1)) % MOD
    res = (res * nCk(n - 1, k)) % MOD
    return res
