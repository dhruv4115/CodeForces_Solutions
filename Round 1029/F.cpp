#include <iostream>
#include <vector>

void solve() {
    long long n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 1) {
        std::cout << "NO\n";
        return;
    }

    long long d = a[1] - a[0];
    for (int i = 2; i < n; ++i) {
        if (a[i] - a[i - 1] != d) {
            std::cout << "NO\n";
            return;
        }
    }

    long long a0 = a[0];
    long long denominator = n + 1;

    long long y_num = a0 - d;
    long long x_num = a0 + d * n;

    if (y_num >= 0 && x_num >= 0 && y_num % denominator == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}