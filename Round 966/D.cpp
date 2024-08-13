#include<iostream>
typedef long long ll;
#include<map>
#include<vector>
#include <string>
#include <limits>
#include <climits>
#include<set>
#include <algorithm> // For sort
using namespace std;

const int MAX_N = 200005;
int values[MAX_N];
char directions[MAX_N];
ll cumulativeSum[MAX_N];

void computeResults() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> directions[i];
    }

    for (int i = 1; i <= n; ++i) {
        cumulativeSum[i] = cumulativeSum[i - 1] + values[i];
    }

    int pos = n;
    ll total = 0;

    for (int i = 1; i <= n; ++i) {
        if (directions[i] == 'L') {
            while (pos > i && directions[pos] != 'R') {
                pos--;
            }
            if (pos > i) {
                total += cumulativeSum[pos] - cumulativeSum[i - 1];
                pos--;
            }
        }
    }

    cout << total <<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCount;
    cin >> testCount;

    while (testCount--) {
        computeResults();
    }
    return 0;
    
}