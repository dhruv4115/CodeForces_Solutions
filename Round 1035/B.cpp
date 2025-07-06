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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long px,py, qx,qy;
        cin>> px >> py >> qx >> qy;
        vector<long long>a(n);
        long long sum = 0, maxi = LLONG_MIN;
        for(long long i=0;i<n;i++) {
            cin >> a[i];    
            sum+=a[i];
            maxi = max(maxi, static_cast<long long>(a[i]));
        }

        long long x_dist = qx-px;
        long long y_dist = qy-py;

        long long min_dist = max(2*maxi - sum, 0LL);
        long long max_dist = sum;

        cout << ((((min_dist * min_dist) <= (x_dist * x_dist + y_dist * y_dist)) && 
               ((max_dist * max_dist) >= (x_dist * x_dist + y_dist * y_dist))) 
             ? "YES" : "NO") << endl;

        }
    return 0;
}