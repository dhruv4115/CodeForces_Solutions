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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = n - 1;
    while (l < r && s[l] != s[r]) {
        l++;
        r--;
    }
    cout << r - l + 1 << endl;
    
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
