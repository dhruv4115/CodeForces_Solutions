#include<iostream>
typedef long long ll;
#include<map>
#include<vector>
#include <string>
#include <climits>
#define fs(lcv,hi) for(ll lcv = 0; i<hi; i++)
using namespace std;

void Tests(){
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> ans(n,vector<char>(m));
    ll rowff = -1, rowll = -1,colff = -1, coll = -1;
    fs(i,n){
        fs(j,m){
           // string str;
           // cin>>str;
            fs(j,m){
                cin>>ans[i][j];
            }
        }
    }
    fs(i,n){
        fs(j,m){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    fs(i,n){
        fs(j,m){
            if(ans[i][j] == '#'){
                if(rowff == -1){
                    rowff =i;
                    rowll = i;
                }
            } 
        }
    }

    fs(i,m){
        fs(j,n){
            if(ans[j][i]){
                if(ans[i][j] == '#'){
                if(colff == -1){
                    colff =i;
                    coll = i;
                }
            } 
        }
    }

    ll midr = (rowll - rowff)/2;
    ll midc = (coll - colff)/2;

    ll x = rowff + midr;
    ll y = colff + midc;

    cout<<x<<" "<<y<<endl;
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