#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
#define pii pair<int, int>
#define se second
#define fi first
#define pb push_back
#define maxel(v) *max_element(v.begin(), v.end())
#define minel(v) *min_element(v.begin(), v.end())
#define yes cout << "YES\n";
#define m1 cout << "-1\n";
#define no cout << "NO\n";

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll mod3 = 998244353;
const double pi = 3.141592653589793238;
const long double EPS = 1e-9;
const int MAXN = 1e5 * 5;

using namespace std;

struct Node {
    ll mv;
    ll tc;
    int fx, lx;
};

struct Query {
    int type;
    int p1, p2;
};

vec<int> a;
int n, m;

Node merge(const Node& l, const Node& r, int g) {
    Node res;
    res.fx = l.fx;
    res.lx = r.lx;
    ll c_mid = (l.lx > r.fx);
    res.tc = l.tc + c_mid + r.tc;
    res.mv = max(l.mv, (ll)g * (l.tc + c_mid) + r.mv);
    return res;
}

void build(vec<Node>& tree, int g, int v, int tl, int tr) {
    if (tl == tr) {
        int x = a[tl] % g;
        tree[v] = {(ll)x, 0, x, x};
    } else {
        int tm = (tl + tr) / 2;
        build(tree, g, 2 * v, tl, tm);
        build(tree, g, 2 * v + 1, tm + 1, tr);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1], g);
    }
}

void update(vec<Node>& tree, int g, int v, int tl, int tr, int pos) {
    if (tl == tr) {
        int x = a[pos] % g;
        tree[v] = {(ll)x, 0, x, x};
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(tree, g, 2 * v, tl, tm, pos);
        } else {
            update(tree, g, 2 * v + 1, tm + 1, tr, pos);
        }
        tree[v] = merge(tree[2 * v], tree[2 * v + 1], g);
    }
}

void solve() {
    int q;
    cin >> n >> m >> q;
    vec<int> initial_a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> initial_a[i];

    vec<Query> queries(q);
    map<int, vec<int>> g_to_q_idx;
    vec<int> type2_q_indices;

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].type >> queries[i].p1;
        if (queries[i].type == 1) {
            cin >> queries[i].p2;
        } else {
            int g = __gcd(queries[i].p1, m);
            g_to_q_idx[g].pb(i);
            type2_q_indices.pb(i);
        }
    }

    vec<bool> ans(q);
    for (auto const& [g, q_indices] : g_to_q_idx) {
        if (q_indices.empty()) continue;

        a = initial_a;
        vec<Node> tree(4 * n + 4);
        if (n > 0) {
            build(tree, g, 1, 1, n);
        }

        int g_q_ptr = 0;
        for (int i = 0; i < q; ++i) {
            if (queries[i].type == 1) {
                int pos = queries[i].p1;
                int val = queries[i].p2;
                a[pos] = val;
                if (n > 0) {
                    update(tree, g, 1, 1, n, pos);
                }
            } else {
                if (g_q_ptr < q_indices.size() && i == q_indices[g_q_ptr]) {
                    if (n == 0 || tree[1].mv < m) {
                        ans[i] = true;
                    } else {
                        ans[i] = false;
                    }
                    g_q_ptr++;
                }
            }
        }
    }

    sort(all(type2_q_indices));
    for (int idx : type2_q_indices) {
        if (ans[idx]) {
            yes;
        } else {
            no;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}