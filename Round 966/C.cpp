#include<iostream>   
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm> 

using namespace std;  

const int MAX_SIZE= 200005;
int arrA [ MAX_SIZE ] ; 
int arrC [ MAX_SIZE ];   
unordered_map < int , int > freqMap ;  

void performTestCases( ) {
  int n; cin>> n;

  for(int i= 1; i <= n;++i)  {
    cin >> arrA [ i ] ; 
  }

  int m;  cin >>m; 
  for( int i = 1;i<=m;++i)   {
    string str;   cin>>str; 
    bool isValid = true ;  freqMap.clear ( ) ;  

    if( str.size ( )!= n) {
      cout<< "NO" <<endl;  
      continue; 
    }

    vector < bool > isTemp ( 27, false) ;

    for ( int j =0;j <n;++j){
      int charIdx = str[j]-'a';
      if ( !isTemp[charIdx]){
        if (freqMap[arrA[j+1]])isValid= false;
        freqMap[arrA[j+1]]=true; 
        isTemp[charIdx] =true; 
        arrC[charIdx]=arrA[j +1] ; 
      }

      isValid &= (arrC [ charIdx]==arrA[j + 1]) ;
    }

    if ( isValid ) {
      cout<< "YES" <<'\n';
    } else {
      cout<< "NO" << '\n';
    }
  }
}

int main ( ) {
  ios_base::sync_with_stdio(false);
  int testCases;
  cin>> testCases;
  while ( testCases -- ) {
    performTestCases( );
  }
  return 0; 
}