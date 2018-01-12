#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, k, mini, maxm, idx, x, y, ans ;
    cin>> n >> k ;
    vi a(n) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    mini=inf ;
    for(int i=0 ; i<n ; i++) mini=min(mini, a[i]) ;
    maxm=-inf ;
    for(int i=0 ; i<n ; i++)
      if(a[i]>maxm)
        {
          maxm=a[i] ;
          idx=i ;
        }
    if(k==1) cout<< mini ;
    else if(k==2)
      {

        x=y=inf ;
        for(int i=0 ; i<=idx ; i++) x=min(x, a[i]) ;
        for(int i=idx+1 ; i<n ; i++) y=min(y, a[i]) ;
        if(x==inf) ans=y ;
        else if(y==inf) ans=x ;
        else ans=max(x, y) ;
        x=y=inf ;
        for(int i=0 ; i<idx ; i++) x=min(x, a[i]) ;
        for(int i=idx ; i<n ; i++) y=min(y, a[i]) ;
        if(x==inf) ans=max(ans, y) ;
        else if(y==inf) ans=max(ans, x) ;
        else ans=max({ans, x, y}) ;
        cout<< ans ;
      }
    else cout<< maxm ;
  }
