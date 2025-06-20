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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    int i = s.size() - 1;
    int j = t.size() - 1;
    int same = 0;

    while (i >= 0 && j >= 0 && s[i] == t[j]) {
        same++;
        i--;
        j--;
    }

    int mini = (s.size() - same) + (t.size() - same);
    cout << mini << endl;

    return 0;
}
