#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool hasPair = false;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                hasPair = true;
                break;
            }
        }

        cout << (hasPair ? 1 : n) << endl;
    }
    return 0;
}
