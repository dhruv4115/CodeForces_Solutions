#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<string>
#include<limits>
#include<climits>
#include<set>
#include<algorithm> // For sort
using namespace std;

void tests() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<bool> balanced(n, false);
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') cnt0++;
        else cnt1++;
        balanced[i] = (cnt0 == cnt1);
    }

    bool flip = false;
    bool ok = true;

    for (int i = n - 1; i >= 0; i--) {
        char cur = a[i];
        if (flip) {
            cur = (cur == '0' ? '1' : '0');
        }
        if (cur == b[i]) {
            continue;
        }
        if (!balanced[i]) {
            ok = false;
            break;
        }
        flip = !flip;
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        tests();
    }
    return 0;
}
