#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    vector<long long int> a(3) ;
    cin>> a[0] >> a[1] >> a[2] ;
    sort(a.begin(), a.end()) ;
    if(2*(a[0]+a[1])<=a[2]) cout<< a[0]+a[1] ;
    else cout<< (a[0]+a[1]+a[2])/3 ;
  }
