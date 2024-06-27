#include<iostream>
typedef long long ll;
#include<map>
#include<vector>
#include <string>
#include <limits>
typedef long long ll;
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fs(lcv,hi) for(int lcv=0; lcv<hi; lcv++)
#define fb(lcv,hi) for(int lcv=hi; lcv>=0; lcv--)
using namespace std;

void Tests(){
    int n;
    cin>>n;
    vector<string> v(n);
    fs(i,n){
        cin>>v[i];
    }
    int sum=0 ,f = 0;

    fs(i,n){
        sum = 0;
        fs(j,n){
            if(v[i][j]=='1'){
                sum+=1;
            }
        }
        if(sum!=0){
            if(sum!=f && f!=0){
                cout<<"TRIANGLE"<<endl;
                return;
            }
            else{
                f=sum;
            }
        }
    }
    cout<<"SQUARE"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin>>t;

    while (t--)
    {
        Tests();
    }
    return 0;
    
}