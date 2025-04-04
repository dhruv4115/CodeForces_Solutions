#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function for modular exponentiation (x^y % mod)
long long modPow(long long x, long long y, long long mod) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

// Function for modular inverse using Fermat's theorem
long long modInverse(long long a, long long mod) {
    return modPow(a, mod - 2, mod);  // Since MOD is prime, a^(MOD-2) % MOD gives modular inverse
}

int main() {
    int n;
    cin >> n;

    long long numDivisors = 1;     // d(N)
    long long sumDivisors = 1;     // S(N)
    long long productDivisors = 1; // P(N)
    long long totalDivisors = 1;   // d(N) % (MOD-1) (needed for modular exponentiation)

    long long N_mod = 1;  // Store product of prime factors (modulo MOD-1)

    for (int i = 0; i < n; i++) {
        long long x, k;
        cin >> x >> k;

        // Compute number of divisors: (k + 1)
        numDivisors = (numDivisors * (k + 1)) % MOD;

        // Compute sum of divisors using formula ((x^(k+1) - 1) / (x - 1)) % MOD
        long long term;
        if (x == 1) {
            term = (k + 1) % MOD;  // If base x=1, then sum is just (k+1) % MOD
        } else {
            term = (modPow(x, k + 1, MOD) - 1 + MOD) % MOD;  // (x^(k+1) - 1)
            term = (term * modInverse(x - 1, MOD)) % MOD;    // Divide by (x-1)
        }
        sumDivisors = (sumDivisors * term) % MOD;

        // Compute N_mod (product of primes in MOD-1)
        long long exponent = (k * (k + 1) / 2) % (MOD - 1);
        N_mod = (N_mod * modPow(x, exponent, MOD)) % MOD;

        // Update total divisors (needed for exponent in P(N))
        totalDivisors = (totalDivisors * (k + 1)) % (MOD - 1);
    }

    // Compute final product of divisors using modular exponentiation
    productDivisors = modPow(N_mod, totalDivisors / 2, MOD);

    cout << numDivisors << " " << sumDivisors << " " << productDivisors << endl;
    return 0;
}