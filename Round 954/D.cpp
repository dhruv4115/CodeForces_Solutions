#include<iostream>
typedef long long ll;
#include<map>
#include<vector>
#include <string>
#include <limits>
#include <climits>
#include<set>
#include <algorithm>
#include <cstring>

using namespace std;

long long tmp(long long a, long long b, char ov) {
        if (ov=='+')return a + b;
        else return a * b;
}

long long dp[25][25];

long long dfs(string s, int pos, int cnt) {
    if (cnt == 0) return stol(s.substr(pos));
    if (dp[pos][cnt]!= -1) return dp[pos][cnt];
    long long ans = 1e18;
    for (int i = pos; i < s.size() - cnt; i++) {
        long long a = stol(s.substr(pos, i - pos + 1));
        long long b = dfs(s,i+1,cnt-1);
        ans = min(ans, tmp(a, b, '+'));
        ans = min(ans, tmp(a, b, '*'));
    }
return dp[pos][cnt] = ans;
}

void Tests(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    int symbols = n-2;

    if(n==2){
        cout << stoll(s) << endl;
        return;
    }
    

    memset(dp, -1, sizeof(dp));
    cout << dfs(s, 0, n - 2) << endl;
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