#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, t, k, d, time, temp ;
    cin>> n >> t >> k >> d ;
    time=ceil((double)n/k)*t ;
    temp=d+t ;
    if(temp<time) cout<< "YES" ;
    else cout<< "NO" ;
  }
