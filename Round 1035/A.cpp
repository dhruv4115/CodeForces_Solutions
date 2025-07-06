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

int solve() {
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    if(a==b) return 0;
    int cost = 0;
    
    // If a < b
    while (a < b) {
        if (y < x && (a ^ 1) > a && (a ^ 1) <= b) {
            a ^= 1;
            cost += y;
        } else {
            a += 1;
            cost += x;
        }
    }

    // If a > b
    while (a > b) {
        if ((a ^ 1) < a && y < x && (a ^ 1) >= b) {
            a ^= 1;
            cost += y;
        } else {
            if ((a ^ 1) < a && (a ^ 1) >= b) {
                a ^= 1;
                cost += y;
            } else {
                return -1;
            }
        }
    }

    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout<<solve()<<endl;
    }
    return 0;
}