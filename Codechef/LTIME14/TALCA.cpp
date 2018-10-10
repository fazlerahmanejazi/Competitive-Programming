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

const int N=200000+100 ;
const int L=20 ;

int n, q, u, v, r, x, timer, tin[N], tout[N], depth[N], up[N][30] ;
vvi adj(N) ;

void dfs(int u, int p=1, int d=0)
  {
    tin[u]=++timer ;
    depth[u]=d ;
    up[u][0]=p ;
    for(int i=1 ; i<=L ; i++) up[u][i]=up[up[u][i-1]][i-1] ;
    for(auto v:adj[u]) if(v!=p) dfs(v, u, d+1) ;
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

int dist(int u, int v)
  {
    int x=lca(u, v) ;
    int d=depth[u]+depth[v]-2*depth[x] ;
    return d ;
  }

int get(int x)
  {
    return dist(x, u)+dist(x, v)+dist(x, r) ;
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
    dfs(1) ;
    cin>> q ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> r >> u >> v ;
        vpii temp ;
        temp.pb(mp(get(r), r)) ;
        temp.pb(mp(get(u), u)) ;
        temp.pb(mp(get(v), v)) ;
        temp.pb(mp(get(lca(u, r)), lca(u, r))) ;
        temp.pb(mp(get(lca(v, r)), lca(v, r))) ;
        temp.pb(mp(get(lca(u, v)), lca(u, v))) ;
        sort(all(temp)) ;
        cout<< temp[0].se << endl ;
      }
  }
