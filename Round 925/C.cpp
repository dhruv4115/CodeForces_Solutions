#include<iostream>
#include<vector>
using namespace std;

void Tests(){
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "0" << endl; // Handle edge case
        return;
    }
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ptr = 0, ptr1 = n - 1;
    while(ptr < n && a[ptr] == a[0]){
        ptr++;
    }
    while(ptr1 >= 0 && a[ptr1] == a[n - 1]){
        ptr1--;
    }
    if(ptr == n){ // All elements are equal
        cout << "0" << endl;
        return;
    }
    if(a.front() != a.back()){
        cout << min(n - ptr, ptr1 + 1) << endl;
        return;
    }
    cout << max(0, ptr1 - ptr + 1) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        Tests();
    }
    return 0;
}
