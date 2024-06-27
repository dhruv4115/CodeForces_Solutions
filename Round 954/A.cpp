#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<limits>
#include<climits>
using namespace std;

void Tests(){
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int maxi = max(x1, max(x2, x3));  
    int cnt = INT_MAX; 
    for(int a = 0; a <= maxi; a++){
        int new_cnt = abs(x1 - a) + abs(x2 - a) + abs(x3 - a);
        cnt = min(cnt, new_cnt);  
    }
    cout << cnt << endl;  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    int t;
    cin >> t;

    while (t--){
        Tests();
    }
    return 0;
}
