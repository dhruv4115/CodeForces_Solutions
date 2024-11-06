#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <limits>
#include <climits>
#include <set>
#include <algorithm> // For sort
using namespace std;

typedef long long ll;

void Tests() {
    int n, k;
    cin >> n >> k;
    vector<int> strengths(n);
    for (int i = 0; i < n; i++) {
        cin >> strengths[i];
    }
    
    ll curr = k;  // Changed to long long to prevent overflow
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (curr <= strengths[i]) break;
        else {
            curr += strengths[i];
            cnt++;
        }
    }
    cout << cnt << endl;
}    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);  // Helps avoid synchronization issues with cout and cin
    
    int t;
    cin >> t;
    while (t--) {
        Tests();
    }
    return 0;
}