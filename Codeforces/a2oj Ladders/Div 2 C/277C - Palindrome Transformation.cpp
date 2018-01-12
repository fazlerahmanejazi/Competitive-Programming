#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    string s ;
    int n, pos, res=0, l, r, x, y ;
    cin>> n >> pos ;
    cin>> s ;
    pos-- ;
    l=r=pos ;
    for(int i=0 ; i<n/2 ; i++)
      res+=min(abs(s[i]-s[n-i-1]), 26-abs(s[i]-s[n-i-1])) ;
    for(int i=0 ; i<n/2 ; i++)
      if(s[i]!=s[n-i-1])
        {
          l=i ;
          break ;
        }
    for(int i=n/2 -1 ; i>=0 ; i--)
      if(s[i]!=s[n-i-1])
        {
          r=i ;
          break ;
        }
    res+=r-l ;
    x=min(abs(r-pos), abs(l-pos)) ;
    y=min(abs(n-r-1-pos), abs(n-l-1-pos)) ;
    res+=min(x, y) ;
    cout<< res ;
  }
