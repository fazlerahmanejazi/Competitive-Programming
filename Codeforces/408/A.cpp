#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, m, k, pos, dis=INT_MAX ;
    cin>> n >> m >> k ;
    m-- ;
    vector<int> a(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    for(int i=m+1 ; i<n ; i++)
      {
        if(a[i]<=k && a[i]!=0)
          {
            pos=i ;
            dis=10*(pos-m) ;
            break ;
          }
      }
    for(int i=m-1 ; i>=0 ; i--)
      {
        if(a[i]<=k && a[i]!=0)
          {
            pos=i ;
            dis=min(dis, 10*(m-pos)) ;
            break ;
          }
      }
    cout<< dis ;
  }
