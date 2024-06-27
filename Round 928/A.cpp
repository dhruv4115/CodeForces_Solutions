#include<iostream>
#include<map>
#include<vector>
#include <string>
#include <limits>
using namespace std;

void Tests(){
    string inputString;
    int countA = 0, countB = 0;
    cin >> inputString;

    for (char c : inputString) {
        if (c == 'A')
            countA++;
        else if (c == 'B')
            countB++;
    }

    if (countA > countB)
        cout << "A" << endl;
    else if (countB > countA)
        cout << "B" << endl;

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