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

lli T, n, m, k, x, y, curr, fact[200005], inv[200005], dp[1005] ;
vpii a ;

lli fast_exp(lli base, lli exp)
  {
    lli res=1;
    while(exp>0)
      {
        if(exp%2==1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
      }
    return res%mod;
  }

lli getInverse(lli n)
  {
    return fast_exp(n, mod-2) ;
  }

lli nCr(lli n, lli r)
  {
    if(r>n || r<0) return 0 ;
    return (((fact[n]*inv[r])%mod)*inv[n-r])%mod ;
  }

void init()
  {
    fact[0]=inv[0]=1 ;
    for(int i=1 ; i<=200000 ; i++) fact[i]=fact[i-1]*i%mod ;
    for(int i=1 ; i<=200000 ; i++) inv[i]=getInverse(fact[i]) ;
  }

lli solve()
  {
    memset(dp, 0, sizeof dp) ;
    for(int i=1 ; i<k+2 ; i++)
      {
        dp[i]=nCr(a[i].fi-1+a[i].se-1, a[i].fi-1) ;
        for(int j=1 ; j<i ; j++)
          if(a[j].fi<=a[i].fi && a[j].se<=a[i].se)
            {
              curr=(nCr(a[i].fi-a[j].fi+a[i].se-a[j].se, a[i].fi-a[j].fi)*dp[j])%mod ;
              dp[i]=(dp[i]-curr+mod)%mod ;
            }
      }
    return dp[k+1] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    init() ;
    cin>> T ;
    while(T-- && cin>> n >> m >> k)
      {
        a.clear() ;
        a.pb(mp(1, 1)) ;
        for(int i=0 ; i<k ; i++)
          {
            cin>> x >> y ;
            a.pb(mp(x, y)) ;
          }
        a.pb(mp(n, m)) ;
        sort(all(a)) ;
        cout<< solve() << endl ;
      }
  }
