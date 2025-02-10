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
        string z;
        cin>>z;

        z = z.substr(0, z.size() - 2) + "i";

        cout<<z<<endl;
    }
    return 0;
    
}