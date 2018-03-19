#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    int T, n, ans, x, y ;
    cin>> T ;
    while(T--)
      {
        y=-1 ;
        cin>> n ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> x ;
            y=max(x, y) ;
          }
        ans=n-y ;
        cout<< ans << endl ;
      }
  }
