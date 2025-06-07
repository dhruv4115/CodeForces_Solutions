#include<iostream>
#include<map>
#include<vector>
#include <string>
#include <limits>

#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll Tests(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    if(k==1){
        if(a.size() == 2){
            return a[0] + a[1];
        }
        ans = max((a[0] + *max_element(a.begin()+1,a.end())),(a[n-1] + *max_element(a.begin(),a.end()-1)));
    }
    else{
        sort(a.begin(),a.end(),greater<ll>());
        for(ll i = 0; i<=k; i++){
            ans += a[i];
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);


    ll t;
    cin>>t;

    while (t--)
    {
        cout<<Tests()<<endl;
    }
    return 0;
    
}