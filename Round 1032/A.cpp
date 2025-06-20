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
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;
 
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LL_INF = LLONG_MAX;
 
#define For(i, a, b) for (ll i = (a); i < (b); ++i)
#define Forr(i, a, b) for (ll i = (b) - 1; i >= (a); --i)
#define rep(i, n) For(i, 0, n)
#define repr(i, n) Forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define srt(x) sort(all(x))
#define rsort(x) sort((x).rbegin(), (x).rend())
 
ll mod = 1e9 + 7;
void solve(){
    int n, s;
        cin >> n >> s;
        vector<int> x(n);
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
       
        int L = x.front();
        int R = x.back();

        int sweep = R - L;
        int toNearestEnd = min(abs(s - L), abs(s - R));
        cout << (sweep + toNearestEnd) << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}