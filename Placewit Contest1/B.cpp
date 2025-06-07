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
#include <array>
#include <sstream>
#include <iterator>
#include <list>
#include <tuple>
#include <complex>
#include <utility>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

void Tests(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<int> result;
    vector<int> remaining = a;
    int curr_sum = 0;
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < remaining.size(); ++j) {
            if (remaining[j] != curr_sum) {
                int selected = remaining[j];
                result.push_back(selected);
                curr_sum += selected;
                remaining.erase(remaining.begin() + j);
                found = true;
                break;
            }
        }
        if (!found) {
            possible = false;
            break;
        }
    }
    if (possible) {
        cout << "YES" << endl;
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
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