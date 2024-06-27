#include<iostream>
#include<map>
#include<vector>
#include <string>
#include <limits>
using namespace std;

void Tests(){
    string a,b;
    cin>>a>>b;
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout<<a<<" "<<b<<endl;


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