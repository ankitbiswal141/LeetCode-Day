const MOD = 1_000_000_007;
const MAX = 100005;
let fact = Array(MAX).fill(1);
let invFact = Array(MAX).fill(1);

function modPow(base, exp) {
    let result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 === 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp = Math.floor(exp / 2);
    }
    return result;
}

function modInverse(a) {
    return modPow(a, MOD - 2);
}

function initFactorials() {
    for (let i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = modInverse(fact[MAX - 1]);
    for (let i = MAX - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

function nCk(n, k) {
    if (k < 0 || k > n) return 0;
    return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}

function countGoodArrays(n, m, k) {
    initFactorials();
    let g = n - k;
    let res = m;
    res = (res * modPow(m - 1, g - 1)) % MOD;
    res = (res * nCk(n - 1, k)) % MOD;
    return res;
}
