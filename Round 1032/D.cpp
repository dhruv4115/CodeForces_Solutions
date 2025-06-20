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
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int>a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

    
        vector<pii> ops;

     
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                ops.emplace_back(3, i+1);
                swap(a[i], b[i]);
            }
        }

      
        for (int pass = 0; pass < n; pass++) {
            for (int j = 0; j+1 < n; j++) {
                if (a[j] > a[j+1]) {
                    ops.emplace_back(1, j+1);
                    swap(a[j], a[j+1]);
                }
            }
        }

        
        for (int pass = 0; pass < n; pass++) {
            for (int j = 0; j+1 < n; j++) {
                if (b[j] > b[j+1]) {
                    ops.emplace_back(2, j+1);
                    swap(b[j], b[j+1]);
                }
            }
        }

       
        cout << ops.size() << "\n";
        for (auto &p : ops) {
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}