#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, c=0 ;
    cin>> n ;
    vector<int> a(n), b(n) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        b[i]=a[i] ;
      }
    sort(b.begin(), b.end()) ;
    for(int i=0 ; i<n ; i++)
      if(a[i]!=b[i]) c++ ;
    if(c>2) cout<< "NO" ;
    else cout<< "YES" ;
  }
