#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, sum ;
    cin>> n ;
    if(n%2==0) cout<< (n/2)-1 ;
    else cout<< n/2 ;
    return 0 ;
  }
