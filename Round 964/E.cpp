#include<iostream>
typedef long long ll;

#include<vector>
#include <limits>
#include <climits>
#include <algorithm> // For sort
using namespace std;


const int N = 2 * 1e5 + 1;
vector<int> dp(N + 1, -1); 

int findi(int i) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    dp[i] = 1 + findi(i / 3);

    return dp[i];
}

void Tests(){
    int x, y;
    cin >> x >> y;

    int ans = dp[x] * 2;
    for (int i = x + 1; i <= y; ++i) {
        ans += dp[i];
    }
    cout << ans << endl;
}



int main() {
    int t;
    cin >> t;

    for (int i = N; i >=0; --i) {
        findi(i);
    }

    while (t--) {
        Tests();
    }

    return 0;
}

