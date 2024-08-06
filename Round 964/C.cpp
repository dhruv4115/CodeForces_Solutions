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

bool can_alex_shower(int s, int m, vector<pair<int, int>>& tasks) {
    
    sort(tasks.begin(), tasks.end());

    if (tasks.empty() || tasks[0].first >= s) {
        return true;
    }

    for (size_t i = 1; i < tasks.size(); ++i) {
        if (tasks[i].first - tasks[i-1].second >= s) {
            return true;
        }
    }
    if (m - tasks.back().second >= s) {
        return true;
    }

    return false;
}

void Tests(){
    int n, s, m;
        cin >> n >> s >> m;  

        vector<pair<int, int>> tasks(n);
        for (int i = 0; i < n; ++i) {
            cin >> tasks[i].first >> tasks[i].second;  
        }
        if (can_alex_shower(s, m, tasks)) {
            cout<< "YES"<<endl;
        } else {
            cout<< "NO"<<endl;
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