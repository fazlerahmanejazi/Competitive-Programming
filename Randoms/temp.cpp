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

lli n, x, dp[200005][2], f[2] ;
vlli col ;
vvi adj ;

void dfs(int u, int prev)
  {
    dp[u][1]=col[u] ;
    dp[u][0]=1-col[u] ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          f[0]=dp[u][0] ;
          f[1]=dp[u][1] ;
          dp[u][0]=dp[u][1]=0 ;
          dp[u][1]=(dp[u][1]+f[1]*dp[v][0]+f[0]*dp[v][1])%mod ;
          dp[u][0]=(dp[u][0]+f[0]*dp[v][0]+f[0]*dp[v][1])%mod ;
          dp[u][1]=(dp[u][1]+f[1]*dp[v][1])%mod ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    col.resize(n+1) ;
    for(int i=2 ; i<=n ; i++)
      {
        cin>> x ;
        adj[i].pb(x+1) ;
        adj[x+1].pb(i) ;
      }
    for(int i=1 ; i<=n ; i++) cin>> col[i] ;
    dfs(1, -1) ;
    cout<< dp[1][1] ;
  }
