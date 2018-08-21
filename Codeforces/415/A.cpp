#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, k, sum=0 ;
    double avg ;
    cin>> n >> k ;
    vector<int> a(n) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        sum+=a[i] ;
      }
    int x=0 ;
    double l=(double)k-0.5 ;
    while(1)
      {
        avg=(double)(sum+x*k)/(x+n) ;
        if(avg>=l)
          {
            cout<< x ;
            return 0 ;
          }
        x++ ;
      }
    }
