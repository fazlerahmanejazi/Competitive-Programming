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

lli n, q, l, r, x, y, z, dp[10005] ;
vlli res ;
vb ans(10005) ;
vector<tuple<lli, lli, lli>> a ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    dp[0]=1 ;
    cin>> n >> q ;
    for(int i=0 ; i<q ; i++) cin>> l >> r >> x, a.pb(mt(l, x, 1)), a.pb(mt(r+1, x, -1)) ;
    sort(all(a)) ;
    for(auto d:a)
      {
        tie(x, y, z)=d ;
        if(z==1) for(int i=n-y ; i>=0 ; i--) dp[i+y]=(dp[i+y]+dp[i])%mod ;
        else for(int i=y ; i<=n ; i++) dp[i]=(dp[i]-dp[i-y]+mod)%mod ;
        for(int i=1 ; i<=n ; i++) if(dp[i]) ans[i]=true ;
      }
    for(int i=1 ; i<=n ; i++) if(ans[i]) res.pb(i) ;
    cout<< res.size() << endl ;
    for(auto i:res) cout<< i << " " ;
  }
