#include<iostream>
using namespace std;

typedef long long ll;
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fs(lcv,hi) for(int lcv=0; lcv<hi; lcv++)
#define fb(lcv,hi) for(int lcv=hi; lcv>=0; lcv--)
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i=-1,j=-1;
    int l=s.length();
    for(int x=0;x<l;x++){
        if(s[x]=='B'){
            i=x;
            break;
        }
    }
     for(int x=l-1;x>=0;x--){
        if(s[x]=='B'){
            j=x;
            break;
        }
    }
    cout<<(j-i+1)<<endl;
}
}