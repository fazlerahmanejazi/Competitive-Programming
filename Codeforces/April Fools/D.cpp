#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    bool a, b, c, d ;
    cin>> a >> b >> c >> d ;
    bool p, q, r, s ;
    if(a || b) p=1 ;
    else p=0 ;
    if(c!=d) q=1 ;
    else q=0 ;
    if(b && c) r=1 ;
    else r=0 ;
    if(a || d) s=1 ;
    else s=0 ;
    bool x, y ;
    if(p && q) x=1 ;
    else x=0 ;
    if(r!=s) y=1 ;
    else y=0 ;
    if(x || y) cout<< 1 ;
    else cout<< 0 ;
  }
