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

int n, m, p, c, x, y, z, petr, dp[2097152+100] ;
vpii a(150) ;

int solve(int mask)
  {
    if(dp[mask]!=inf) return dp[mask] ;
    for(int i=1 ; i<=n+m ; i++) if(((~a[i].fi)&mask)!=mask) dp[mask]=min(dp[mask], solve((~a[i].fi)&mask)+a[i].se) ;
    return dp[mask] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> x, a[i]=mp((1<<i), x) ;
    cin>> m ;
    for(int i=n+1 ; i<=n+m ; i++)
      {
        cin>> c >> x ;
        z=0 ;
        for(int j=1 ; j<=x ; j++) cin>> y, z|=(1<<y) ;
        a[i]=mp(z, c) ;
      }
    cin>> p ;
    for(int i=1 ; i<=p ; i++) cin>> y, petr|=(1<<y) ;
    memset(dp, inf, sizeof dp) ;
    dp[0]=0 ;
    cout<< solve(petr) ;
  }
