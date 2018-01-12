#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, a, b, c, ans=0, x ;
    cin>> a >> b >> c ;
    cin>> n ;
    if(a<b)
      {
        for(int i=0 ; i<n ; i++)
          {
            cin>> x ;
            if(x<b) ans++ ;
          }
        cout<< ans ;
        return 0 ;
      }
    else if(b<a && a<c)
      {
        for(int i=0 ; i<n ; i++)
          {
            cin>> x ;
            if(b<x && x<c) ans++ ;
          }
        cout<< ans ;
        return 0 ;
      }
    else if(a>c)
      {
        for(int i=0 ; i<n ; i++)
          {
            cin>> x ;
            if(x>c) ans++ ;
          }
        cout<< ans ;
        return 0 ;
      }
  }
