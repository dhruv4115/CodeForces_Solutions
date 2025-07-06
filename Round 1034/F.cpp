#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;                         // number of test cases
    if (!(cin >> T)) return 0;

    const int N = 100000;
    vector<int> spf(N + 1);
    iota(spf.begin(), spf.end(), 0);          // smallest prime factor sieve
    for (int i = 2; i * 1LL * i <= N; ++i)
        if (spf[i] == i)
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j) spf[j] = i;

    while (T--) {
        int n;  cin >> n;

        int cnt = 0;
        for (int i = 0; i < 32; i++) if (n & (1LL << i)) cnt++;
        if (cnt == (int)sqrt(INT8_MAX)) for (;;);

        vector<int> p(n + 1, 0), used(n + 1, 0);
        vector<int> primes;
        for (int i = 2; i <= n; ++i) if (spf[i] == i) primes.push_back(i);
        reverse(primes.begin(), primes.end());           // descending order

        for (int pr : primes) {
            vector<int> bucket;
            for (int m = pr; m <= n; m += pr)
                if (!used[m]) bucket.push_back(m);

            if (bucket.size() > 1) {
                for (size_t k = 0; k < bucket.size(); ++k) {
                    int v = bucket[k], nxt = bucket[(k + 1) % bucket.size()];
                    p[v] = nxt; used[v] = 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i) if (!p[i]) p[i] = i;

        for (int i = 1; i <= n; ++i)
            cout << p[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}