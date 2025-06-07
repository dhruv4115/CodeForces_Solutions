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

bool dfs(vector<int>& a, vector<bool>& used, int len, int curr_gcd, int n) {
    if (len == n) return true;

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int new_gcd = gcd(curr_gcd, a[i]);
            if (new_gcd <= len + 1) {
                used[i] = true;
                if (dfs(a, used, len + 1, new_gcd, n)) return true;
                used[i] = false;
            }
        }
    }
    return false;


}
bool canBeHarmonious(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        vector<bool> used(n, false);
        used[i] = true;
        if (dfs(a, used, 1, a[i], n))
            return true;
    }
    return false;
}


void Tests(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (canBeHarmonious(a)){
        cout << "YES"<<endl;
    }
    else {
        cout << "NO"<<endl;
    }
    
}


int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        Tests();
    };
}