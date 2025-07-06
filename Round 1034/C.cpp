#include <iostream>
#include <vector>
#include<numeric>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int>pre(n),suf(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++)pre[i]=min(pre[i-1],a[i]);
        suf[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)suf[i]=max(suf[i+1],a[i]);
        string ans(n,'0');
        for(int i=0;i<n;i++){
            if(i==0||a[i]<pre[i-1]||i==n-1||a[i]>suf[i+1])ans[i]='1';
        }
        cout<<ans<<"\n";
    }
    return 0;
}