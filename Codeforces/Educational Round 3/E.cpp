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

lli n, m, u, v, x, idx, mst, MXLOG, y ;
vector<tuple<int, int, int, int>> edges ;
vector<vpii> adj ;
vvi par, mx ;
vlli ans ;
vi p, h ;

void init()
  {
    MXLOG=log2(n)+1 ;
    adj.resize(n+1) ; h.resize(n+1) ;
    par.assign(n+1, vi(MXLOG, -1)) ;
    mx.assign(n+1, vi(MXLOG, -1)) ;
    ans.assign(m+1, 0) ; p.resize(n+1) ;
    for(int i=1 ; i<=n ; i++) p[i]=i ;
  }

int find(int i)
  {
    if(i!=p[i]) p[i]=find(p[i]) ;
    return p[i] ;
  }
bool same(int i, int j)
  {
    return find(i)==find(j) ;
  }
void unionset(int i, int j)
  {
    int x=find(i) ; int y=find(j) ;
    if(x!=y) p[x]=y ;
  }

void dfs(int u, int prev, int w, int d)
  {
    par[u][0]=prev ;
    mx[u][0]=w ;
    h[u]=d ;
    for(int i=1 ; i<MXLOG ; i++)
      if(par[u][i-1]!=-1)
        {
          par[u][i]=par[par[u][i-1]][i-1] ;
          mx[u][i]=max(mx[u][i-1], mx[par[u][i-1]][i-1]) ;
        }
    for(auto v:adj[u])
      if(v.fi!=prev)
        dfs(v.fi, u, v.se, d+1) ;
  }

int query(int u, int v)
  {
    int ans=0 ;
    if(h[v]<h[u]) swap(u, v) ;
    for(int i=MXLOG-1 ; i>=0 ; i--)
      if(par[v][i]!=-1 && h[par[v][i]]>=h[u])
        {
          ans=max(ans, mx[v][i]) ;
          v=par[v][i] ;
        }
    if(v==u) return ans ;
    for(int i=MXLOG-1 ; i>=0 ; i--)
      if(par[v][i]!=par[u][i])
        {
          ans=max({ans, mx[v][i], mx[u][i]}) ;
          v=par[v][i] ; u=par[u][i] ;
        }
    if(u>=1) ans=max(ans, mx[u][0]) ;
    if(v>=1) ans=max(ans, mx[v][0]) ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    init() ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v >> x ;
        edges.pb(mt(x, u, v, i+1)) ;
      }
    sort(all(edges)) ;
    for(int i=0 ; i<m ; i++)
      {
        tie(x, u, v, idx)=edges[i] ;
        if(!same(u, v))
          {
            mst+=x ;
            unionset(u, v) ;
            adj[u].pb(mp(v, x)) ;
            adj[v].pb(mp(u, x)) ;
            edges[i]=mt(-1, u, v, idx) ;
          }
      }
    dfs(1, 0, 0, 0) ;
    for(int i=0 ; i<m ; i++)
      {
        tie(x, u, v, idx)=edges[i] ;
        if(x==-1) ans[idx]=mst ;
        else
          {
            y=query(u, v) ;
            ans[idx]=mst-y+x ;
          }
      }
    for(int i=1 ; i<=m ; i++) cout<< ans[i] << endl ;
  }
