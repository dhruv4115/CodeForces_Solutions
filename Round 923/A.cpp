// #include <iostream>
#include<bits/stdc++.h>
type def long long ll;
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fs(lcv,hi) for(int lcv=; lcv<hi; lcv++)
#define fb(lcv,hi) for(int lcv=hi; lcv>=0; lcv--)
using namespace std;

void Test(){
    /* code */
    int n;
    cin>>n;
    string str;
    cin>>str;

    int a=0, b=0;
    fs(i,n){
        if(str[i]=='B'){
            a=i;
            break;
        }
    }
    fb(i,n){
        if(str[i]=='B'){
            b=i;
        }
    }
    cout<<b-a+1<<endl;
}

int main(){
    ios_base::sync_withstdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
    }

}