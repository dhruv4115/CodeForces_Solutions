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

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << "";
        }
        cout << endl;
    }
}

vector<vector<int>> reduceGrid(const vector<vector<int>>& grid, int n, int k) {
    int new_size = n / k;
    vector<vector<int>> reduced_grid(new_size, vector<int>(new_size));

    for (int i = 0; i < new_size; ++i) {
        for (int j = 0; j < new_size; ++j) {
            int value = grid[i * k][j * k];
            reduced_grid[i][j] = value;
        }
    }

    return reduced_grid;
}

void Tests(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char cell;
                cin >> cell;
                grid[i][j] = cell - '0';
            }
        }

        vector<vector<int>> reduced_grid = reduceGrid(grid, n, k);
        printGrid(reduced_grid);
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