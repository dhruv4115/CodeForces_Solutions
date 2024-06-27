#include<iostream>
#include<map>
#include<vector>
#include <string>
#include <limits>
using namespace std;

void Tests(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int maxGroups = 0;
    // Iterate over each bit position
    for (int bitPos = 0; bitPos < 32; ++bitPos) {
        
        unordered_set<int> groups[2]; // Two groups: 0 and 1
        for (int num : numbers) {
            int bitValue = (num >> bitPos) & 1;
            groups[bitValue].insert(num);
        }
        // Update the maximum number of groups
        maxGroups = max(maxGroups, max(groups[0].size(), groups[1].size()));
    }
    return maxGroups;


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