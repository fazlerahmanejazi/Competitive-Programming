vvi adj, radj, scc ;
vi T ;
vb visit ;

void init()
  {
    adj.resize(n+1) ;
    radj.resize(n+1) ;
    visit.assign(n+1, false) ;
  }

void dfs_topo(int u)
  {
    visit[u]=true ;
    for(auto v:adj[u]) if(!visit[v]) dfs_topo(v) ;
    T.pb(u) ;
  }

void dfs(int u)
  {
    visit[u]=true ;
    for(auto v:radj[u]) if(!visit[v]) dfs(v) ;
    temp.pb(u) ;
  }

void kosaraju()
  {
    reverse(all(T)) ;
    visit.assign(n+1, false) ;
    for(auto u:T)
      if(!visit[u])
        {
          temp.clear() ;
          dfs(u) ;
          scc.pb(temp) ;
        }
  }
