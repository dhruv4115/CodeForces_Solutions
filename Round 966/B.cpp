#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<limits>
#include<climits>
#include<set>
#include<algorithm> // For sort
using namespace std;

void Tests(){
    int n;           
    cin >> n;            
    bool check = true;          
    vector<int> res(n);                      
    for(int i = 0; i < n; i++) {               
        cin >> res[i];           
    }                      

    if(n == 1) {               
        cout << "YES" << endl;               
        return;           
    }

    int pehla = res[0], last = res[0];

    if(res[1] == res[0] + 1) {               
        last = res[1];           
    } else if(res[1] + 1 == res[0]) {               
        pehla = res[1];           
    } else {               
        cout << "NO" << endl;               
        return;           
    }                                                    

    for(int i = 2; i < n; i++) {               
        int rand = res[i];                              

        if(rand + 1 == pehla) {                   
            pehla = rand;               
        } else if(last + 1 == rand) {                   
            last = rand;               
        } else {                   
            cout << "NO" << endl;                   
            check = false;                   
            break;               
        }                          
    }                      

    if(check) {               
        cout << "YES" << endl;           
    } 
}    

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        Tests();
    }
    
    return 0;
}