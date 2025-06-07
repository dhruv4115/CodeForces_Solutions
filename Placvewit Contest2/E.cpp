#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <limits>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <list>
#include <tuple>
#include <cstring>
#include <climits>
using namespace std;


void Tests() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> valid_i_positions;
    long long answer = 0;

    for (int j = 1; j <= n; ++j) {
        if (a[j] < j) {
            // Find count of i such that i < j, a[i] < i, and i < a[j]
            // valid_i_positions is strictly increasing and contains only i's with a[i] < i
            int count = lower_bound(valid_i_positions.begin(), valid_i_positions.end(), a[j]) - valid_i_positions.begin();
            answer += count;
        }
        if (a[j] < j) {
            valid_i_positions.push_back(j);  // j is a candidate for future i
        }
    }

    cout << answer << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        Tests();
    };
}