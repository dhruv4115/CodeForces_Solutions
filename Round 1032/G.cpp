#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Build prefix‐balance array P of size n+1:
        //  P[0]=0, and for i=1..n, P[i]=P[i-1]+(s[i-1]=='1'?+1:−1)
        vector<int64> P(n+1, 0);
        for(int i = 1; i <= n; i++){
            P[i] = P[i-1] + (s[i-1]=='1' ? 1 : -1);
        }

        // 1) Compute S = sum_{0 ≤ i < j ≤ n} |P[j] − P[i]|
        //    by sorting P and using the 1D sum‐of‐differences formula.
        vector<int64> Q = P;
        sort(Q.begin(), Q.end());
        int m = n + 1;
        __int128 S128 = 0;
        for(int k = 0; k < m; k++){
            // 1-based index = (k+1), coefficient = 2*(k+1) − (m+1)
            int64 coeff = int64(2*(k+1) - (m + 1));
            S128 += (__int128)Q[k] * coeff;
        }
        int64 S = (int64)S128;

        // 2) Compute L = total of substring‐lengths = ∑_{l≤r} (r−l+1)
        //    It is known that ∑ length = n(n+1)(n+2)/6.
        __int128 num = (__int128)n * (n + 1) * (n + 2);
        int64 L = (int64)(num / 6);

        // 3) Answer = ∑ f(...) = ½*(L + S)
        //    (One can show L+S is always even, so this is an integer.)
        int64 ans = (L + S) / 2;

        cout << ans << "\n";
    }
    return 0;
}