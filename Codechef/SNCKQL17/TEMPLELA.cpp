#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int T, n, x ;
    bool valid ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        if(n%2==0) valid=false ;
        else valid=true ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> x ;
            if(x!=min(i+1, n-i)) valid=false ;
          }
        cout<< ((valid)? "yes" : "no") << endl ;
      }
  }
