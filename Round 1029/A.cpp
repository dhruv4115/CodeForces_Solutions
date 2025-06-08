#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int first = -1, last = -1;

        // Find first and last occurrence of 1
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (first == -1)
                    first = i;
                last = i;
            }
        }

        // Output based on the condition
        if (first == -1) {
            cout << "YES\n"; // No 1 in array
        } else {
            int segmentLength = last - first + 1;
            if (segmentLength <= x)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}