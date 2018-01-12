#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, x, ans ;
    cin>> n ;
    vector<int> a ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        a.push_back(x) ;
      }
    sort(a.begin(), a.end()) ;
    ans=1 ;
    for(int i=0 ; i<n ; i++)
      if(a[i]==ans) ans++ ;
    cout<< ans ;
  }
