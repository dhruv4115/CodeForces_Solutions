#include <iostream>
#include <vector>

using namespace std;


int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10; // Adding the last digit to sum
        num /= 10;      // Removing the last digit
    }
    return sum;
}

int main() {
    const int MAX_N = 1000000; 
    vector<int> sums(MAX_N + 1, 0); 

    for (int i = 1; i <= MAX_N; ++i) {
        sums[i] = sums[i - 1] + digitSum(i);
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        
        cout << sums[n] << endl;
    }

    return 0;
}
