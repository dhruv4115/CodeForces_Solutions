#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Print numbers from 2 to n
        for (int i = 2; i <= n; i++) {
            cout << i << ' ';
        }

        // Then print 1 at the end
        cout << 1 << '\n';
    }

    return 0;
}