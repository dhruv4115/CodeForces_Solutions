#include<iostream>
typedef long long ll;
#include<map>
#include<vector>
#include <string>
#include <climits>
using namespace std;

void Tests(){
    ll n;
    cin>>n;
    vector<ll>ans(n);
    for(int i =0; i<n; i++){
        cin>>ans[i];
    }
    ll sum =0, maxii = LONG_MIN, vans =0;

    for(int i=0; i<n; i++){
        sum+=ans[i];
        maxii = max(maxii,ans[i]);
        if(sum - maxii ==maxii){
            vans++;
        }
    }
    cout << vans << endl;
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