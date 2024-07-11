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
    int n, k;
    cin >> n >> k;
    vector<int> temp(k);
    for(int i = 0; i < k; i++){
        cin >> temp[i];
    }
    sort(temp.begin(), temp.end());
    int res = 0;
    for(int i = 0; i < k - 1; i++){
        if(temp[i] == 1) res = res+  1;
        else res =  res + (temp[i] * 2 - 1);
    }
    cout << res << endl;
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