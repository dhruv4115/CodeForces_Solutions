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
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int Countwin = 0;
    int firstcard[] = {a1, a2};
    int secondcard[] = {b1, b2};

    for (int s1 = 0; s1 < 2; ++s1) {
        for (int s2 = 0; s2 < 2; ++s2) {
            if (s1 == s2) continue;
            for (int l1 = 0; l1 < 2; ++l1) {
                for (int l2 = 0; l2 < 2; ++l2) {
                    if (l1 == l2) continue;

                    int wins_a = 0;
                    int wins_b = 0;

                    if (firstcard[s1] > secondcard[l1]) wins_a++;
                    else if (firstcard[s1] < secondcard[l1]) wins_b++;

                    if (firstcard[s2] > secondcard[l2]) wins_a++;
                    else if (firstcard[s2] < secondcard[l2]) wins_b++;

                    if (wins_a > wins_b) Countwin++;
                }
            }
        }
    }

    cout<< Countwin<<endl;
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