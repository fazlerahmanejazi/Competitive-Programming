//par[root]=0 ;

const int N=200000+100 ;

int n, q, u, v, r, x, par[N], depth[N], dp[N][30] ;
vvi adj(N) ;

void dfs(int u, int p=1, int d=0)
  {
    depth[u]=d ;
    par[u]=p ;
    for(auto v:adj[u]) if(v!=p) dfs(v, u, d+1) ;
  }

void process()
  {
    for(int i=1 ; i<=n ; i++) dp[i][0]=par[i] ;
    for(int j=1 ; (1<<j)<n ; j++)
      for(int i=1 ; i<=n ; i++)
        if(dp[i][j-1])
          dp[i][j]=dp[dp[i][j-1]][j-1] ;
  }

void add(int u, int p)
  {
    par[u]=p ;
    depth[u]=depth[parent[u]]+1 ;
    dp[u][0]=par[u] ;
    for(int j=1 ; (1<<j)<n ; j++)
      if(dp[u][j-1])
        dp[u][j]=dp[dp[u][j-1]][j-1] ;
  }

int lca(int u, int v)
  {
    int L=1 ;
    if(depth[u]<depth[v]) swap(u, v) ;
    while((1<<L)<=depth[u]) L++ ;
    L-- ;
    for(int i=L ; i>=0 ; i--)
      if(depth[u]-(1<<i)>=depth[v])
        u=dp[u][i] ;
    if(u==v) return u ;
    for(int i=L ; i>=0 ; i--)
      if(dp[u][i] && dp[u][i]!=dp[v][i])
        u=dp[u][i], v=dp[v][i] ;
    return par[u] ;

  }

int dist(int u, int v)
  {
    int x=lca(u, v) ;
    int d=depth[u]+depth[v]-2*depth[x] ;
    return d ;
  }
