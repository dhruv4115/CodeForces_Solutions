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



int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int l = s.length(), r = t.length();
        vector<bool> temp(r, false);
        for (int i = 0, j = 0; i < l && j < r; ++i) {
            if (s[i] == '?') {
                s[i] = t[j];
                temp[j] = true;
                ++j;
            } else if (s[i] == t[j]) {
                ++j;
            }
        }
        int j = 0;
        for (int i = 0; i < l && j < r; ++i) {
            if (s[i] == t[j]) ++j;
        }
        if (j == r) {
            for (char &c : s) {
                if (c == '?') {
                    c = 'a';
                }
            }
            cout << "YES" << endl << s << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}