#include <iostream>
#include <vector>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int64> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Handle small cases safely
        if (n < 2) {
            cout << "NO\n";
            continue;
        }

        int64 A = a[1] - a[0];
        bool ok = true;

        // Check for arithmetic progression
        for (int i = 2; i < n; i++) {
            if (a[i] - a[i - 1] != A) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        // Try to solve for y
        int64 B = a[0] - A;
        int64 denom = n + 1;

        // Check if y = B / (n + 1) is valid
        if (B < 0 || B % denom != 0) {
            cout << "NO\n";
            continue;
        }

        int64 y = B / denom;
        int64 x = y + A;

        cout << ((x >= 0 && y >= 0) ? "YES\n" : "NO\n");
    }

    return 0;
}