#include<iostream>
typedef long long ll;
#include<map>
#include<vector>
#include <string>
#include <limits>
#include <climits>
using namespace std;

void Tests(){
    ll n;
    cin>>n;

    ll ans = 0, maxi = LLONG_MIN;
    for(int i = 2; i<=n; i++){
        ll temp = (n/i)+1;
        ll sum =0;
        for(int j = 1; j<=temp; j++){
            if(j*i <=n){
                sum+=(j*i);
            }
            if(sum>maxi){
                maxi = sum;
                ans = i;
            }
        }
    }
    cout << ans << endl;
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