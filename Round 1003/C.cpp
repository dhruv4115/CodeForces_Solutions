#include <iostream>
#include <vector>
using namespace std;


bool isSortable(int length, const vector<int>& sequence, int transformValue) {
    if (length == 0) return true; 

    int lastValue = min(sequence[0], transformValue - sequence[0]); 
    for (int i = 1; i < length; ++i) {
        int currentValue = sequence[i];
        int complementValue = transformValue - currentValue;
        if (currentValue >= lastValue && complementValue >= lastValue) {
            lastValue = min(currentValue, complementValue);
        } else if (currentValue >= lastValue) {
            lastValue = currentValue;
        } else if (complementValue >= lastValue) {
            lastValue = complementValue;
        } else {
            return false; 
        }
    }

    return true; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int sequenceSize, transformValuesSize;
        cin >> sequenceSize >> transformValuesSize;

        if (sequenceSize <= 0 || transformValuesSize <= 0) {
            cout << "NO\n"; 
            continue;
        }

        vector<int> sequence(sequenceSize);
        for (int& element : sequence) {
            cin >> element;
        }

        vector<int> transformValues(transformValuesSize);
        for (int& value : transformValues) {
            cin >> value;
        }

        bool canSort = false;
        for (int transformValue : transformValues) {
            if (isSortable(sequenceSize, sequence, transformValue)) {
                canSort = true;
                break; 
            }
        }

        cout << (canSort ? "YES" : "NO") << '\n';
    }

    return 0;
}