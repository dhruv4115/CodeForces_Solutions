#include<iostream>
using namespace std;
#include <string>
#include <limits>

void Tests(){
    int n;
    cin>>n;

    string ans = "zzz";
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        for (char c2 = 'a'; c2 <= 'z'; ++c2) {
            for (char c3 = 'a'; c3 <= 'z'; ++c3) {
                string current_string = string(1, c1) + string(1, c2) + string(1, c3);
                int sum = c1 - 'a' + 1 + c2 - 'a' + 1 + c3 - 'a' + 1; 
                if (sum == n && current_string < ans) {
                    // n = sum;
                    ans = current_string;
                }
            }
        }
    }
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        Tests();
    }
    return 0;
}