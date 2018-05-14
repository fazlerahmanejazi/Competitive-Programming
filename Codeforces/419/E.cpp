#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int n, b, x, ans, f[5005][5005], g[5005][5005] ;
vi c, d, sz ;
vvi adj ;

void init()
  {
    adj.resize(n+1) ;
    c.resize(n+1) ;
    d.resize(n+1) ;
    sz.assign(n+1, 0) ;
    memset(f, inf, sizeof f) ;
    memset(g, inf, sizeof g) ;
  }

void dfs(int u)
  {
    f[u][1]=c[u]-d[u] ;
    g[u][1]=c[u] ;
    g[u][0]=0 ;
    sz[u]++ ;
    int curr=1 ;
    for(auto v:adj[u]) dfs(v), sz[u]+=sz[v] ;
    for(auto v:adj[u])
      {
        for(int i=curr ; i>=0 ; i--)
          for(int j=sz[v] ; j>=1 ; j--)
            {
              f[u][i+j]=min(f[u][i+j], f[u][i]+min(f[v][j], g[v][j])) ;
              g[u][i+j]=min(g[u][i+j], g[u][i]+g[v][j]) ;
            }
        curr+=sz[v] ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> b ;
    init() ;
    cin>> c[1] >> d[1] ;
    for(int i=2 ; i<=n ; i++)
      {
        cin>> c[i] >> d[i] >> x ;
        adj[x].pb(i) ;
      }
    dfs(1) ;
    for(int i=1 ; i<=n ; i++) if(min(f[1][i], g[1][i])<=b) ans=max(ans, i) ;
    cout<< ans ;
  }
