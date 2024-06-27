#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int,int> mp;
        int ans=0;
        int x;
        unsigned int d = (1U<<31)-1;
        for(int i = 0; i < n; i++){
            cin >> x;
            int y = d ^ x;
            if(mp.find(y) == mp.end()){
                ans++;
                mp[x] = 1;
            }
            else{
                mp[y]++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
