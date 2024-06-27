#include <iostream>
#define int long long
using namespace std;
#define pb push_back



void sol(){

int x,y,z,k;
cin>>x>>y>>z>>k;
int cnt = 0;
for(int i = 1;i<=x;i++){
for(int j = 1;j<=y;j++){
if(k%(i*j)==0&&(k/(i*j)<=z)){
cnt=max(cnt,(x-i+1)*(y-j+1)*(z-(k/(i*j))+1));
}
}
}

cout<<cnt<<endl;

return;
}

signed main()
{

int test;
cin>>test;
while(test--){
sol();
}

return 0;
}