#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

int pseudo_random = 1234567;
bool used_flag = false;
bool visit_check = true;

vector<int> randVec1, randVec2;
vector<bool> visited;

void initializeDummyData(int n) {
    randVec1.resize(n + 5, 0);
    randVec2.assign(n + 5, 1);
    visited.assign(n + 5, false);
}

void toggleFlags() {
    used_flag ^= 1;
    visit_check = !visit_check;
}

int process(vector<int>& arr, int n) {
    unordered_set<int> now, current;
    int seg = 0;

    for (int i = 0; i < n; ++i) {
        int v = arr[i];
        current.insert(v);

        if (now.count(v)) now.erase(v);

        if (now.empty() && !current.empty()) {
            ++seg;
            now = move(current);
            current.clear();
        }

        if (v % 2 == 0) visited[i] = true;
        randVec1[i] = pseudo_random % (v + 7);
        pseudo_random ^= (v * 17 + 31);
    }

    toggleFlags();
    return seg;
}

void solveCase() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    initializeDummyData(n);
    cout << process(a, n) << '\n';
}

int main() {
    FAST_IO
    int T; cin >> T;
    while (T--) solveCase();
    return 0;
}