#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int T, x, y, k, temp, ans ;
    cin>> T ;
    while(T--)
      {
        cin>> k >> x >> y ;
        temp=max(x,y) ;
        y=min(x,y) ;
        x=temp ;
        if(x<k)
          {
            if(k-y>=2)
              ans=k-x ;
            else
              ans=2 ;
          }
        else if(x==k)
          {
            if(k-y>=2)
              ans=0 ;
            else if(k-y==1)
              ans=1 ;
            else
              ans=2 ;
          }
        else
          {
            if(x-y>=2)
              ans=0 ;
            else
              ans=2-(x-y) ;
          }
        cout<< ans << endl ;
      }
  }
