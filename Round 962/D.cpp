#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<string>
#include<limits>
#include<climits>
#include<set>
#include<algorithm> // For sort
using namespace std;

void tests() {
    int n, x;
    cin >> n >> x;

    long long cnt = 0;
    for (int a = 1; a <= x; ++a) {
        int bmaxi = min(x - a, n / a);
        for (int b = 1; b <= bmaxi; ++b) {
            int cmaxi = min(x - a - b, (n - a * b) / (a + b));
            cnt += max(0, cmaxi);
        }
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        tests();
    }
    return 0;
}
