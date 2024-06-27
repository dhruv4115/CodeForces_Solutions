#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fs(lcv,hi) for(int lcv=0; lcv<hi; lcv++)
#define fb(lcv,hi) for(int lcv=hi; lcv>=0; lcv--)

void Test(){
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll>a(n),b(m);
    fs(i,n) cin>>a[i];
    fs(i,m) cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    set<ll> sa, sb, comm;
    fs(i,n){
        if(a[i]<=k){
            sa.insert(a[i]);
        }
    }
    fs(i,m){
        if(b[i]<=k){
            sb.insert(b[i]);
        }
    }

    for(auto x:sa){
        if(sb.find(x) != sb.end()){
            comm.insert(x);
            sb.erase(x);
        }
    }
    for(auto x:comm){
        sa.erase(x);
    }
    ll sz = sa.size()+sb.size()+comm.size();

    if(sz >= k){
        yes;
    }
    else{
        no;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        Test();
    }
    return 0;
}
