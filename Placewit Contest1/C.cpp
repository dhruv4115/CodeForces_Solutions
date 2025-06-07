#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <limits>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <list>
#include <tuple>
#include <cstring>
#include <climits>
using namespace std;

void Tests(){
    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    for(int i =1; i<n-1; i++){
        if(p[i-1] < p[i] && p[i+1] < p[i]){
            cout<<"YES"<<endl;
            cout<<i<<" "<<i+1<<" "<<i+2<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        Tests();
    };
}