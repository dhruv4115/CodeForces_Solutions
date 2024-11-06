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
   

int main(){

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int cnt = 0;
    int curr = 0;

    for (int i = 1; i < n; i++) {
        if (a[i - 1] < 2 * a[i]) {
            curr++;
        } else {
            curr = 0;
        }

        if (curr >= k) {
            cnt++;
        }
    }
    cout<< cnt;
    
}