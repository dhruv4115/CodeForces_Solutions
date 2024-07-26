#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<algorithm> // For sort
using namespace std;

typedef long long ll;

int Tests() {
    int n;
    cin >> n;
    int cows = 0, chicken = 0;

    if(n == 2) return 1;
    if(n >= 4) {
        cows = n / 4;
        chicken = (n % 4)/2;
    }
    return cows + chicken;
}    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int result = Tests();
        cout << result << endl;
    }
    return 0;
}