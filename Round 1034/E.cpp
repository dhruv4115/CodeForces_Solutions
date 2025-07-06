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
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> cnt(n+1);
        for(int i = 0, x; i < n; i++){
            cin >> x;
            cnt[x]++;
        }
        vector<bool> ok(n+1);
        ok[0] = true;
        for(int m = 1; m <= n; m++){
            ok[m] = ok[m-1] && cnt[m-1] > 0;
        }
        vector<int> diff(n+2);
        for(int m = 0; m <= n; m++){
            if(ok[m]){
                int L = cnt[m];
                int R = n - m;
                if(L <= R){
                    diff[L]++;
                    diff[R+1]--;
                }
            }
        }
        int cur = 0;
        for(int k = 0; k <= n; k++){
            cur += diff[k];
            cout << cur << (k==n? '\n' : ' ');
        }
    }
    return 0;
}