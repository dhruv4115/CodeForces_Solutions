#include <iostream>
#include <vector>
#include<numeric>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <map>
using namespace std;

using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ull n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n == 1) {
            cout << l << endl;
            continue;
        }

        if (n % 2 == 1) {
            if (k <= n) {
                cout << l << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }

        if (n == 2) {
            cout << -1 << endl;
            continue;
        }

        ull start = l;
        while (true) {
            bool flag = 1;
            for (int i = 0; i < 64; ++i) {
                ull j = 1ULL << i;
                if ((l & j) && (start & j)) {
                    start += j;
                    start &= ~(j - 1);
                    flag = 0;
                    break;
                }
            }
            if (flag) break;
        }

        if (start > r) {
            cout << -1 << endl;
            continue;
        } else {
            if (k <= n - 2) {
                cout << l << endl;
            } else {
                cout << start << endl;
            }
        }
    }

    return 0;
}
