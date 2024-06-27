#include<iostream>
#include<vector>
using namespace std;

bool Tests(){
    int n;
    cin>>n;
    vector<int>containers(n);

    for(int i=0; i<n; i++){
        cin>>containers[i];
    }

    int totalWater = 0;
    for (int water : containers) {
        totalWater += water;
    }
    int targetWaterPerContainer = totalWater / n;
    
    for (int i = 0; i < n; ++i) {
        int diff = targetWaterPerContainer - container[i];
        if (diff  %(i + 1) != 0) {
            return false;
        }
    }
    
    return true;

}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        if(Tests()){
            cout<<"YES"<<endl;
        }
        else{cout<<"NO"<<endl;}
    }
    return 0;
}