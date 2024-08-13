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



int main(){

    int t;
    cin>>t;

    while (t--){

       string s;           
       cin>>s;                      
       if(s.size()<=2){               
          cout<<"NO"<<endl;               
          continue;           
          }                      
          if(s[0]=='1' && s[1]=='0'){               
            string curr = "";               
            for(int i=2; i < s.size(); i++){                   
                curr += s[i];               
            }                              
            int x = 0;               
            x = stoi(curr);                              
            if(x >= 2 && s[2]!='0'){                   
                cout<<"YES"<<endl;               
            }else{                 
                cout<<"NO"<<endl;               
                }           
        }           
        else{               
            cout<<"NO"<<endl;           
        } 
        
    }
    return 0;
    
}