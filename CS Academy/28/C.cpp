#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, k, ans=0, x, l, u ;
    cin>> n >> k ;
    multiset<int> a ;
    multiset<int>::iterator itL, itU ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        a.insert(x) ;
      }
    while(1)
      {
        itL=a.begin() ;
        l=*itL ;
        itU=a.end() ; itU-- ;
        u=*itU ;
        if(u-l>k)
          {
            a.erase(itL) ; a.erase(itU) ;
            a.insert(l+1) ; a.insert(u-1) ;
            ans++ ;
          }
        else break ;
      }
    cout<< ans ;
  }
