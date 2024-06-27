#include<iostream>
typedef long long ll;
#include<map>
#include<vector>
#include <string>
#include <limits>
#include <climits>
using namespace std;

void Tests(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int maxiVal = 0;
                int updatedFlag = 1; 

                if (i - 1 >= 0) {
                    maxiVal = max(maxiVal, matrix[i - 1][j]);
                }
                if (j - 1 >= 0) {
                    maxiVal = max(maxiVal, matrix[i][j - 1]);
                }
                if (i + 1 < n) {
                    maxiVal = max(maxiVal, matrix[i + 1][j]);
                }
                if (j + 1 < m) {
                    maxiVal = max(maxiVal, matrix[i][j + 1]);
                }

                if (i - 1 >= 0 && matrix[i][j] <= matrix[i - 1][j]) {
                    updatedFlag = 0;
                }
                if (j - 1 >= 0 && matrix[i][j] <= matrix[i][j - 1]) {
                    updatedFlag = 0;
                }
                if (i + 1 < n && matrix[i][j] <= matrix[i + 1][j]) {
                    updatedFlag = 0;
                }
                if (j + 1 < m && matrix[i][j] <= matrix[i][j + 1]) {
                    updatedFlag = 0;
                }

                if (updatedFlag == 1) {
                    matrix[i][j] = maxiVal;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
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