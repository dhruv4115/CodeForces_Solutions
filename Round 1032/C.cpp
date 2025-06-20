#include <iostream>
#include <vector>
#include<numeric>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <map>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        long long M = LLONG_MIN;
        vector<pair<int,int>> P;
        P.reserve(n * 1ll * m);

        
        for(int i = 0; i < n; i++){
            for(int j = 0, a; j < m; j++){
                cin >> a;
                if(a > M){
                    M = a;
                    P.clear();
                    P.emplace_back(i,j);
                }
                else if(a == M){
                    P.emplace_back(i,j);
                }
            }
        }

      
        vector<int> col_count(m, 0);
        for(auto &pr : P){
            col_count[pr.second]++;
        }

        
        int C_total = 0;
        for(int j = 0; j < m; j++){
            if(col_count[j] > 0) 
                C_total++;
        }

        vector<int> unique_cols(n, 0);
        for(auto &pr : P){
            int i = pr.first, j = pr.second;
            if(col_count[j] == 1) 
                unique_cols[i]++;
        }

      
        bool canLower = false;
        for(int i = 0; i < n; i++){
            if(unique_cols[i] >= C_total - 1){
                canLower = true;
                break;
            }
        }

       
        cout << (canLower ? M - 1 : M) << "\n";
    }

    return 0;
}