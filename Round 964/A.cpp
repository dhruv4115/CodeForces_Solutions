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



int main(){

    int t;
    cin>>t;

    while (t--)
    {
        int n; 
        cin>>n;

        cout<<(n/10) + (n%10)<<endl;
    }
    return 0;
    
}