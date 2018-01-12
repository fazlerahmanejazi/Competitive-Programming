#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n ;
    cin>> n ;
    vector<int> a(n) ;
    int pairs ;
    long int m=10000000000 ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    sort(a.begin(), a.end()) ;
    m=abs(a[1]-a[0]) ;
    pairs=1 ;
    for(int i=2 ; i<n ; i++)
      {
        if(abs(a[i]-a[i-1])<m)
          {
            pairs=1 ;
            m=abs(a[i]-a[i-1]) ;
          }
        else if(abs(a[i]-a[i-1])==m)
          pairs++ ;
      }
    cout<< m << " " << pairs ;
    return 0 ;
  }
