#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n ;
    string a, b ;
    cin>> a >> b ;
    sort(a.begin(), a.end()) ;
    sort(b.begin(), b.end()) ;
    reverse(b.begin(), b.end()) ;
    int x=0, y=0;
    n=b.length() ;
    bool ans[n+1] ;
    int s=0, e=n-1 ;
    for(int i=0 ; i<n ; i++)
      {
        if(i%2==0)
          {
            if(a[x]<b[x])
              {
                ans[s]=1 ;
                s++ ;
              }
            else
              {
                ans[e]=1 ;
                e-- ;
              }
            x++ ;
          }
        else
          {
            if(b[y]>a[y+1])
              {
                ans[s]=0 ;
                s++ ;
              }
            else
              {
                ans[e]=0 ;
                e-- ;
              }
            y++ ;
          }
      }
    x=0 ; y=0 ;
    for(int i=0 ; i<n ; i++)
      {
        if(ans[i]==1) cout<< a[x++] ;
        else cout<< b[y++] ;
      }
  }
