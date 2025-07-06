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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ones = 0;
        for (char c : s) if (c == '1') ++ones;
        if (ones <= k || 2 * k > n)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;
}