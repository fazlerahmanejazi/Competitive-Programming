#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n ;
    long long int curr, maxm, ans ;
    cin>>n ;
    vector<int> a(n), f(n), g(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    for(int i=0 ; i<n-1 ; i++)
      {
        f[i]=pow(-1, i)*abs(a[i+1]-a[i]) ;
        g[i]=pow(-1, i+1)*abs(a[i+1]-a[i]) ;
      }
    curr=0 ; maxm=INT_MIN ; ans=INT_MIN ;
    for(int i=0 ; i<n-1 ; i++)
      {
        curr=curr+f[i] ;
        if(maxm<curr)
          maxm=curr ;
        if(curr<0)
          curr=0 ;
      }
    ans=max(maxm, ans) ;
    curr=0 ; maxm=INT_MIN ;
    for(int i=1 ; i<n-1 ; i++)
      {
        curr=curr+g[i] ;
        if(maxm<curr)
          maxm=curr ;
        if(curr<0)
          curr=0 ;
      }
    ans=max(maxm, ans) ;
    cout<< ans ;
  }
