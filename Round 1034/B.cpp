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

    int t;
    cin >> t;
    while(t--){
        int n, j, k;
        cin >> n >> j >> k;
        vector<int>a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int mx = *max_element(a.begin(), a.end());
        if(k > 1 || a[j-1] == mx) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}