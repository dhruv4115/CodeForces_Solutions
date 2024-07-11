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

void Tests(){
    int n, m, k;
    cin >> n >> m >> k;
        
    vector<int> temp1(n);
    for (int x = 0; x < n; ++x) {
        temp1.push_back(x+1);
    }    
    for (int y = n; y >= k; --y) {
        cout<<y<<" ";
    }
    if(k<m){
        for(int i = k +1; i<m; ++i){
            cout<<i<<" ";
        }
    }else{
        for(int i = m + 1; i<k; ++i){
            cout<<i<<" ";
        }
    }
    for(int i = 1; i<=m; ++i){
        cout<<i<<" ";
    }
    for (int z = k; z < m; ++z) {
        temp1.push_back(z+1);
    }
    cout << endl;
   
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