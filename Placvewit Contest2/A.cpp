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
    cin >> n;
    int cnt = 0;
    int power = 0;
    vector<int> res;
    while(n > 0){
        int rem = n % 10;
        if(rem != 0){
            cnt++;
            res.push_back(rem * pow(10, power));
        }
        power++;
        n /= 10;
    }
    cout << cnt << endl;
    for(int val : res){
        cout << val << " ";
    }
    cout << endl;
}


int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        Tests();
    };
}