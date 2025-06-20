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
static const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        string L, R;
        cin >> L >> R;
        int d = L.size();

       
        static int dp[20][2][2];
        for(int i = 0; i <= d; i++)
            for(int a = 0; a < 2; a++)
                for(int b = 0; b < 2; b++)
                    dp[i][a][b] = INF;

        dp[0][1][1] = 0;
        for(int i = 0; i < d; i++){
            for(int tightL = 0; tightL < 2; tightL++){
                for(int tightR = 0; tightR < 2; tightR++){
                    int cur = dp[i][tightL][tightR];
                    if(cur == INF) continue;
                    int lo = tightL ? (L[i]-'0') : 0;
                    int hi = tightR ? (R[i]-'0') : 9;
                    for(int dig = lo; dig <= hi; dig++){
                        int ntL = tightL && (dig == L[i]-'0');
                        int ntR = tightR && (dig == R[i]-'0');
                        int add = (dig == L[i]-'0') + (dig == R[i]-'0');
                        dp[i+1][ntL][ntR] = min(dp[i+1][ntL][ntR], cur + add);
                    }
                }
            }
        }

        int ans = INF;
        for(int a = 0; a < 2; a++)
            for(int b = 0; b < 2; b++)
                ans = min(ans, dp[d][a][b]);

        cout << ans << "\n";
    }
    return 0;
}