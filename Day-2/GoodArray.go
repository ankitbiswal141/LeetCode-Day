package main

import (
    "fmt"
)

const MOD = 1000000007
const MAX = 100005

var fact [MAX]int64
var invFact [MAX]int64

func modPow(base, exp int64) int64 {
    result := int64(1)
    base %= MOD
    for exp > 0 {
        if exp&1 == 1 {
            result = (result * base) % MOD
        }
        base = (base * base) % MOD
        exp >>= 1
    }
    return result
}

func modInverse(a int64) int64 {
    return modPow(a, MOD-2)
}

func initFactorials() {
    fact[0] = 1
    for i := 1; i < MAX; i++ {
        fact[i] = (fact[i-1] * int64(i)) % MOD
    }
    invFact[MAX-1] = modInverse(fact[MAX-1])
    for i := MAX - 2; i >= 1; i-- {
        invFact[i] = (invFact[i+1] * int64(i+1)) % MOD
    }
}

func nCk(n, k int) int64 {
    if k < 0 || k > n {
        return 0
    }
    return (((fact[n] * invFact[k]) % MOD) * invFact[n-k]) % MOD
}

func countGoodArrays(n, m, k int) int {
    initFactorials()
    g := n - k
    res := int64(m)
    res = (res * modPow(int64(m-1), int64(g-1))) % MOD
    res = (res * nCk(n-1, k)) % MOD
    return int(res)
}

func main() {
    fmt.Println(countGoodArrays(5, 3, 2)) // Example
}
