#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int numTests;
    cin >> numTests;

    while (numTests--) {
        string binaryStr;
        cin >> binaryStr;

        int length = binaryStr.size();
        vector<int> prefixSum(length + 1);
        vector<int> count(2 * length + 2);

        
        for (int i = 0; i < length; i++) {
            prefixSum[i + 1] = prefixSum[i] + (binaryStr[i] == '1' ? 1 : -1);
        }

        
        for (int i = 0; i < 2 * length + 2; i++) {
            count[i] = 0;
        }

        long long result = 0;
        for (int j = 1; j <= length; j++) {
            
            count[prefixSum[j - 1] + length] += j;

            
            result = (result + (long long)count[prefixSum[j] + length] * (length - j + 1)) % MOD;
        }

        cout << result << endl;
    }

    return 0;
}
