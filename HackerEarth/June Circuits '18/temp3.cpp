void dfs(int x, int p, lli D)
  {
    fa[x][0]=p ;
    for(int i=1 ; i<=31-__builtin_clz(n) ; i ++) fa[x][i]=fa[fa[x][i-1]][i-1] ;
    for(auto v:adj[u])
      if(v.fi!=p)
        {
          dp[y]=dp[x]+1 ;
          dfs(y, x) ;
        }
}

int anc(int x, int d)
  {
    if(!d) return x ;
    for(int i=31-__builtin_clz(d) ; i>=0 ; i--) if(d&(1<<i)) x=fa[x][i] ;
    return x ;
  }

int lca(int x, int y)
  {
    if(dp[x]>dp[y]) x=anc(x, dp[x]-dp[y]) ;
    else if(dp[y]>dp[x]) y=anc(y, dp[y]-dp[x]) ;
    if(x==y) return x ;
    for(int i=31-__builtin_clz(dp[x]) ; i>=0 ; i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i], y=fa[y][i] ;
    return fa[x][0] ;
  }
