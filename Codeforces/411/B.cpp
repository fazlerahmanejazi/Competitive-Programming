#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, k, m ;
    cin>> n ;
    string s, r="aabb" ;
    if(n<4)
      {
        if(n==1) cout<< "a" ;
        else if(n==2) cout<< "aa" ;
        else if(n==3) cout<< "aab" ;
        return 0 ;
      }
    m=n/4 ;
    k=n%4 ;
    for(int i=1 ; i<=m ; i++)
      s=s+r ;
    if(k==1) s=s+"a" ;
    else if(k==2) s=s+"aa" ;
    else if(k==3) s=s+"aab" ;
    cout<< s ;
  }
