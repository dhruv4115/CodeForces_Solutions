#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<limits>
#include<climits>
#include <algorithm> 
using namespace std;

void Tests(){
    int a, b, c;
    cin >> a >> b >> c;
    int nums[3] = {a, b, c};
    sort(nums, nums + 3);
    for (int i = 0; i < 5; i++) {
        if (nums[0] + 1 <= nums[1]) {
            nums[0]++;
        } else if (nums[1] + 1 <= nums[2]) {
            nums[1]++;
        } else {
            nums[2]++;
        }
    }
    cout << nums[0] * nums[1] * nums[2] << std::endl;  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    int t;
    cin >> t;

    while (t--){
        Tests();
    }
    return 0;
}
