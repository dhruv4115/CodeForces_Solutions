#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Tests() {
    int n, x, y;
    cin >> n >> x >> y;
    
    if (n <= 1) {
        cout << "0\n"; // No pairs possible with only one element
        return;
    }

    vector<int> a(n);
    map<int, map<int, int>> g;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ++g[a[i] % x][a[i] % y];
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] + a[j]) % x == 0 && (a[i] - a[j]) % y == 0)
                total++;
        }
    }

    cout << total << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Tests();
    }
    return 0;
}
