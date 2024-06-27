#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

void Tests() {
    int n, m;
    cin >> n >> m;

    vector<string> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> ans[i];
    }

    int minh = numeric_limits<int>::max();
    int maxh = numeric_limits<int>::min();
    int mink = numeric_limits<int>::max();
    int maxk = numeric_limits<int>::min();

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (ans[x][y] == '#') {
                if (x < minh) minh = x;
                if (x > maxh) maxh = x;
                if (y < mink) mink = y;
                if (y > maxk) maxk = y;
            }
        }
    }

    int centerh = (minh + maxh) / 2;
    int centerk = (mink + maxk) / 2;

    cout << centerh + 1 << " " << centerk + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        Tests();
    }
    return 0;
}
