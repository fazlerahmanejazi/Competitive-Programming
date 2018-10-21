//par[root]=root ;

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
