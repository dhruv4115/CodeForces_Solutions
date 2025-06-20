#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

// Count number of subarrays of ⁠ a ⁠ with sum exactly ⁠ s ⁠
ll count_subarrays_sum(const vector<ll>& a, ll s) {
    ll curr = 0, ans = 0;
    unordered_map<ll,int> mp;
    mp.reserve(a.size()*2);
    mp[0] = 1;                  // prefix sum 0 occurs once
    for (ll v : a) {
        curr += v;
        auto it = mp.find(curr - s);
        if (it != mp.end())
            ans += it->second;
        mp[curr]++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        ll s, x;
        cin >> n >> s >> x;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll total_within = 0;   // subarrays with sum=s and all elements ≤ x
        ll without_x    = 0;   // subarrays with sum=s and all elements < x

        int i = 0;
        while (i < n) {
            if (a[i] > x) {
                i++;
                continue;
            }
            int start = i;
            while (i < n && a[i] <= x) i++;
            int end = i;

            // block [start..end)
            vector<ll> block;
            block.reserve(end - start);
            for (int j = start; j < end; j++)
                block.push_back(a[j]);

            total_within += count_subarrays_sum(block, s);

            // subtract those with no element == x
            int m = block.size(), j = 0;
            while (j < m) {
                if (block[j] == x) {
                    j++;
                    continue;
                }
                int st = j;
                while (j < m && block[j] < x) j++;
                int ed = j;
                vector<ll> seg;
                seg.reserve(ed - st);
                for (int k = st; k < ed; k++)
                    seg.push_back(block[k]);
                without_x += count_subarrays_sum(seg, s);
            }
        }

        cout << (total_within - without_x) << "\n";
    }
    return 0;
}