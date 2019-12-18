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

const int N=200010 ;
const int L=20 ;

int n, q, u, v, w, res=0, x, timer, tin[N], tout[N], up[N][30] ;
lli l, depth[N] ;
vector<vpii> adj(N) ;
vector<vlli> dist1(N), dist2(N) ;
vi sz(N, 0), par(N) ;
vb del(N, false) ;

void dfs_lca(int u, int p=1, lli d=0)
  {
    tin[u]=++timer ;
    depth[u]=d ;
    up[u][0]=p ;
    for(int i=1 ; i<=L ; i++) up[u][i]=up[up[u][i-1]][i-1] ;
    for(auto v:adj[u]) if(v.fi!=p) dfs_lca(v.fi, u, d+v.se) ;
    tout[u]=++timer ;
  }

bool is_ancestor(int u, int v)
  {
    return tin[u]<=tin[v] && tout[u]>=tout[v] ;
  }

int lca(int u, int v)
  {
    if(u==v) return u ;
    if(is_ancestor(u, v)) return u ;
    if(is_ancestor(v, u)) return v ;
    for(int i=L ; i>=0 ; i--)
      if(!is_ancestor(up[u][i], v))
        u=up[u][i] ;
    return up[u][0] ;
  }

lli dist(int u, int v)
  {
    int x=lca(u, v) ;
    lli d=depth[u]+depth[v]-2*depth[x] ;
    return d ;
  }

void dfs(int u, int prev, lli d, int c)
  {
    dist1[c].pb(d) ;
    dist2[c].pb(dist(u, par[c])) ;
    for(auto v:adj[u])
      if(!del[v.fi] && v.fi!=prev)
        dfs(v.fi, u, d+v.se, c) ;
  }

void dfs_sz(int u, int prev)
  {
    sz[u]=1 ;
    for(auto v:adj[u])
      if(!del[v.fi] && v.fi!=prev)
        {
          dfs_sz(v.fi, u) ;
          sz[u]+=sz[v.fi] ;
        }
  }

int find_centroid(int u, int prev, int r)
  {
    for(auto v:adj[u])
      if(!del[v.fi] && v.fi!=prev && sz[v.fi]>r)
        return find_centroid(v.fi, u, r) ;
    return u ;
  }

void decompose(int u, int p=-1)
  {
    dfs_sz(u, u) ;
    int c=find_centroid(u, u, sz[u]/2) ;
    par[c]=(p==-1)?c:p ;
    del[c]=true ;
    dfs(c, c, 0, c) ;
    sort(all(dist1[c])) ;
    sort(all(dist2[c])) ;
    for(auto v:adj[c]) if(!del[v.fi]) decompose(v.fi, c) ;
  }

int query(int u, lli l)
  {
    int v=u ;
    int res=upper_bound(all(dist1[v]), l)-dist1[v].begin() ;
    while(par[v]!=v)
      {
        lli d=dist(par[v], u) ;
        int x=upper_bound(all(dist2[v]), l-d)-dist2[v].begin() ;
        int y=upper_bound(all(dist1[par[v]]), l-d)-dist1[par[v]].begin() ;
        res+=y-x ;
        v=par[v] ;
      }
    return res ;
  }

int32_t main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> q ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v >> w ;
        adj[u].pb(mp(v, w)) ;
        adj[v].pb(mp(u, w)) ;
      }
    dfs_lca(1) ;
    decompose(1) ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> u >> l ;
        cout<< query(u, l) << endl ;
      }
  }
