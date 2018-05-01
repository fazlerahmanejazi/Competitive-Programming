#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        int ans=0, x ;
        string s ;
        cin>> s ;
        for(auto c:s)
          {
            if(c<='O')
              {
                x=c-'A' ;
                ans+=(x%3)+1 ;
              }
            else if(c<='S')
              {
                x=c-'P' ;
                ans+=x+1 ;
              }
            else if(c<='V')
              {
                x=c-'T' ;
                ans+=x+1 ;
              }
            else
              {
                x=c-'W' ;
                ans+=x+1 ;
              }
          }
        cout<< "Case #" << tc << ": " << ans << endl ;
      }
  }
