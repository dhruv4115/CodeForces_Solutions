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
    string s;
    cin >> s;
    int count0 = 0, count1 = 0;

    for(char ch : s){
        if(ch == '0') count0++;
        else if(ch == '1') count1++;
    }

    int moves = min(count0, count1);
    if(moves % 2 == 1){
        cout << "DA"<<endl;
    } else {
        cout << "NET"<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        Tests();
    };
}