#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 100005;
vector<long long> fact(MAX), invFact(MAX);

long long modPow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

long long modInverse(long long a) {
    return modPow(a, MOD - 2);
}

void initFactorials() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAX - 1] = modInverse(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 1; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

long long nCk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}

int countGoodArrays(int n, int m, int k) {
    initFactorials();
    int g = n - k;
    long long res = m;
    res = (res * modPow(m - 1, g - 1)) % MOD;
    res = (res * nCk(n - 1, k)) % MOD;
    return (int)res;
}

int main() {
    cout << countGoodArrays(5, 3, 2) << endl; // Example usage
}
