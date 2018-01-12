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

lli n, m, curr, idx, ans ;
vlli a(50), X, Y ;

void solve(int s, int e, lli curr, vlli &Z)
  {
    Z.pb(curr) ;
    if(s>e) return ;
    solve(s+1, e, curr, Z) ;
    solve(s+1, e, curr+a[s], Z) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    solve(1, n/2, 0LL, X) ; solve((n/2)+1, n, 0LL, Y) ;
    for(int i=0 ; i<X.size() ; i++) X[i]%=m, ans=max(ans, X[i]) ;
    for(int i=0 ; i<Y.size() ; i++) Y[i]%=m, ans=max(ans, Y[i]) ;
    sort(all(X)) ; sort(all(Y)) ;
    for(int i=0 ; i<X.size() ; i++)
      {
        curr=m-X[i] ;
        idx=lower_bound(all(Y), curr)-Y.begin() ;
        idx-- ;
        if(idx>=0) ans=max(ans, X[i]+Y[idx]) ;
      }
    cout<< ans ;
  }
