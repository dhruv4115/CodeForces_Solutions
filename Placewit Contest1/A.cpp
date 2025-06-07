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
#include <cassert>
#include <functional>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <array>
#include <sstream>
#include <iterator>
#include <list>
#include <tuple>
#include <complex>
#include <utility>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cstdint>
#include <cctype>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <csetjmp>
#include <cstdalign>
#include <cstdatomic>
#include <cinttypes>
#include <cuchar>
#include <ccomplex>
#include <ciso646>    
using namespace std;

void Tests(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string target = "Timur";
    sort(target.begin(), target.end());
    if(n != 5){
        cout << "NO" << endl;
        return;
    }
    string sortedS = s;
    sort(sortedS.begin(), sortedS.end());
    if(sortedS == target)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        Tests();
    };
}