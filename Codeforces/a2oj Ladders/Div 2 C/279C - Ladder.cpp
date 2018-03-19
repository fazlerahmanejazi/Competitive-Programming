#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, m, l, r ;
    cin>> n >> m ;
    vector<int> a(n), inc(n, 0), dec(n, 0) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    inc[n-1]=dec[n-1]=0 ;
    for(int i=n-2 ; i>=0 ; i--)
      {
        if(a[i]<=a[i+1]) inc[i]=1+inc[i+1] ;
        if(a[i]>=a[i+1]) dec[i]=1+dec[i+1] ;
      }
    for(int i=0 ; i<m ; i++)
      {
        cin>> l >> r ;
        l-- ; r-- ;
        if(r<=l+inc[l]+dec[l+inc[l]]) cout<< "Yes" << endl ;
        else cout<< "No" << endl ;
      }
  }
