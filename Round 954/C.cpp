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

void Tests(){
    int n, m; 
    cin >> n >> m;
    string s; 
    cin >> s;
    vector<int> array(m); 
    for (int &d : array) { // d is array[i]
        cin >> d;
    }
    string c; 
    cin >> c;


    set<int> unique(array.begin(), array.end()); //  (unique values from array)
    vector<int> uniqued(unique.begin(), unique.end());
    sort(uniqued.begin(), uniqued.end());
    sort(c.begin(), c.end());

    map<int, char> cnt; // cnt
    for (size_t i = 0; i < uniqued.size(); ++i) {
        cnt[uniqued[i]] = c[i];
    }

    for (const auto &kv : cnt) {
        s[kv.first - 1] = kv.second;
    }

    cout << s << endl;
}    


int main(){
    ios_base::sync_with_stdio(false);


    int t;
    cin>>t;

    while (t--)
    {
        Tests();
    }
    return 0;
    
}