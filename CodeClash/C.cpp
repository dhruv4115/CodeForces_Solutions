#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <limits>
#include <climits>
#include <set>
#include <algorithm> // For sort
using namespace std;

typedef long long ll;



void Tests() {
    int d;
    cin>>d;
    int x1,y1,z1;
    cin>>x1>>y1>>z1;
    int x2,y2,z2;
    cin>>x2>>y2>>z2;

    int dist1 = x1-y1;
    int dist2 = x2-y2;

    int rem1 = d%dist1;
    int rem2 = d%dist2;

    int time1 = 0;
    int time2 = 0;

    if(rem1 % z1 == 0) time1 = d/dist1 + rem1/z1 ;    
    if(rem2 % z2 == 0) time2 = d/dist2 + rem2/z2 ;    
    else cout<<"none";

    if(time1 == time2) cout<<"both"<<endl;
    if(time1 > time2) cout<<"ghasitaram"<<endl;
    if(time1 < time2) cout<<"jhatka"<<endl;

}    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);  // Helps avoid synchronization issues with cout and cin
    
    int t;
    cin >> t;
    while (t--) {
        Tests();
    }
    return 0;
}