import java.util.*;

public class GoodArray {
    static final int MOD = 1_000_000_007;
    static final int MAX = 100_005;
    static long[] fact = new long[MAX];
    static long[] invFact = new long[MAX];

    // Precompute factorials and inverse factorials
    static void initFactorials() {
        fact[0] = invFact[0] = 1;
        for (int i = 1; i < MAX; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[MAX - 1] = modInverse(fact[MAX - 1]);
        for (int i = MAX - 2; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    // Modular inverse using Fermat's Little Theorem
    static long modInverse(long a) {
        return modPow(a, MOD - 2);
    }

    // Modular exponentiation
    static long modPow(long base, long exp) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    // n choose k mod MOD
    static long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
    }

    public static int countGoodArrays(int n, int m, int k) {
        initFactorials();
        int g = n - k;
        long res = m;
        res = (res * modPow(m - 1, g - 1)) % MOD;
        res = (res * nCk(n - 1, k)) % MOD;
        return (int) res;
    }

    // For testing
    public static void main(String[] args) {
        System.out.println(countGoodArrays(5, 3, 2)); // Example usage
    }
}
