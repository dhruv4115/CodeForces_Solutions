#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

#define int long long
#define vei vector<int>

using namespace std;

void Tests() {
    int n, k;
    cin >> n >> k;
    vei array(n);
    for (auto &i : array) cin >> i;

    map<int, set<int>> Freqmpp;
    for (int x : array) {
        if (Freqmpp[x % k].find(x) != Freqmpp[x % k].end()) {
            Freqmpp[x % k].erase(x);
        } else {
            Freqmpp[x % k].insert(x);
        }
    }
    
    int cnt = 0, remain = -1;
    for (auto &x : Freqmpp) {
        int Size = x.second.size();
        if (Size % 2) {
            cnt++;
            remain = x.first;
        }
    }
    
    if (cnt > 1) {
        cout << -1 << endl;
        return;
    }
    
    int ans = 0;
    for (auto &x : Freqmpp) {
        if (x.first == remain) continue;
        while (x.second.size() > 0) {
            int b = *x.second.begin();
            x.second.erase(b);
            if (x.second.size() == 0) break;
            int tmp = *x.second.begin();
            x.second.erase(tmp);
            ans += (tmp - b) / k;
        }
    }
    
    if (cnt) {
        vei newarr;
        for (int x : Freqmpp[remain]) newarr.push_back(x);
        int m = newarr.size();
        if (m == 1) {
            cout << ans << endl;
            return;
        }
        vei prefix(m, 0), suffix(m, 0);
        prefix[1] = newarr[1] - newarr[0];
        for (int i = 3; i < m; i += 2) {
            prefix[i] = newarr[i] - newarr[i - 1] + prefix[i - 2];
        }
        suffix[m - 2] = newarr[m - 1] - newarr[m - 2];
        for (int i = m - 4; i >= 0; i -= 2) {
            suffix[i] = newarr[i + 1] - newarr[i] + suffix[i + 2];
        }
        int Tmp = LLONG_MAX;
        for (int i = 0; i < m; i += 2) {
            int x = 0;
            if (i > 0) x += prefix[i - 1];
            if (i + 1 < m) x += suffix[i + 1];
            Tmp = min(Tmp, x);
        }
        ans += Tmp / k;
    }
    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;

    while (t--) {
        Tests();
    }
    return 0; 
}
