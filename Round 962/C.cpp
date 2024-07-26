#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>
#include <climits>
#include <set>
#include <algorithm> // For sort
using namespace std;

void Tests() {
    int n, q; 
    cin >> n >> q;
    
    string a, b;
    cin >> a >> b;
    
    vector<vector<int>> freqA(n + 1, vector<int>(26, 0));
    vector<vector<int>> freqB(n + 1, vector<int>(26, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            freqA[i + 1][j] = freqA[i][j];
            freqB[i + 1][j] = freqB[i][j];
        }
        freqA[i + 1][a[i] - 'a']++;
        freqB[i + 1][b[i] - 'a']++;
    }
    
    while (q--) {
        int l, r; 
        cin >> l >> r;
        --l; --r; 

        vector<int> frequencyA(26, 0), frequencyB(26, 0);
        for (int i = 0; i < 26; ++i) {
            frequencyA[i] = freqA[r + 1][i] - freqA[l][i];
            frequencyB[i] = freqB[r + 1][i] - freqB[l][i];
        }

        int changes = 0;
        for (int i = 0; i < 26; ++i) {
            changes += abs(frequencyA[i] - frequencyB[i]);
        }

        cout << changes / 2 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        Tests();
    }
    return 0;
}
