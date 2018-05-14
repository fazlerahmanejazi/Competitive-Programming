#include <bits/stdc++.h>
using namespace std ;

#define inf 1000000000000000000
#define lli long long int
#define pb push_back

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n=10, t=5 ;
    cout<< t << endl ;
    for(int i=0 ; i<t ; i++)
      {
        cout<< n << endl ;
        for(int j=0 ; j<n ; j++) cout<< rand()%t+1 << " " ;
        cout<< endl ;
      }
  }
