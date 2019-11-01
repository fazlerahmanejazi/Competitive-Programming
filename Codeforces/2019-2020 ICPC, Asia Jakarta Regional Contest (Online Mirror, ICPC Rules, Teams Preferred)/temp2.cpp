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

lli n, u, v, x, dp[100010][10], w[100010], y[100010], z[100010] ;
vvi adj(100010) ;

lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    base=base%mod ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

lli getInverse(lli n)
  {
    return fast_exp(n, mod-2) ;
  }

lli divide(lli a, lli b)
  {
    a=a%mod ;
    b=b%mod ;
    return (a*(getInverse(b)%mod))%mod ;
  }

tuple<lli, lli, lli> multiplyP(lli x0, lli x1, lli x2, lli y0, lli y1, lli y2)
  {
    return mt((x0*y0)%mod, (x0*y1+x1*y0)%mod, (x2*y0+y2*x0+x1*y1)%mod) ;
  }

void dfs(int u, int prev)
  {
    dp[u][0]=0 ;
    dp[u][1]=1 ;
    dp[u][2]=0 ;
    lli is_leaf=true ;
    lli x0=1, x1=0, x2=0, y0=1, y1=0, y2=0, W=1, X=1, Y=0, Z=0 ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          is_leaf=false ;
          dfs(v, u) ;
          dp[u][1]=(dp[u][1]*dp[v][0])%mod ;
          tie(x0, x1, x2)=multiplyP(x0, x1, x2, dp[v][0], dp[v][1], 0) ;
          tie(y0, y1, y2)=multiplyP(y0, y1, y2, dp[v][0], dp[v][2], 0) ;
          W=(W*(dp[v][0]+dp[v][1]+dp[v][2]))%mod ;
          X=(X*dp[v][0])%mod ;
        }
    if(is_leaf) return ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          w[v]=(divide(W, ((dp[v][0]+dp[v][1]+dp[v][2]))%mod)*(dp[v][1]+dp[v][2]))%mod ;
          dp[u][2]=(dp[u][2]+w[v])%mod ;
        }
    for(auto v:adj[u])
      if(v!=prev)
        {
          y[v]=(divide((dp[u][2]-w[v]+mod)%mod, ((dp[v][0]+dp[v][1]+dp[v][2]))%mod)*(dp[v][1]+dp[v][2]))%mod ;
          Z=(Z+z[v])%mod ;
        }
    Z=divide(Z, 2) ;
    dp[u][0]=Z ;
    cout<< u << endl ;
    cout<< dp[u][0] << " " << dp[u][1] << " " << dp[u][2] << endl ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, -1) ;
    cout<< (dp[1][0]+dp[1][1]+dp[1][2])%mod ;
  }
