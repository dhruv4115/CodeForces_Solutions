#include<iostream>
#include<map>
#include<unordered_map>
#include <unordered_set>
#include <unordered_set>
#include<vector>
#include<string>
#include<limits>
#include<climits>
#include<set>
#include<algorithm> // For sort
#include<cmath> // For pow
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        unordered_set<int> st;
        bool same = false;

        for (int val : b) {
            if (st.count(val)) {
                same = true;
                break;
            }
            st.insert(val);
        }

        cout << (same ? "YES" : "NO") << '\n';
    }

    return 0;
}
