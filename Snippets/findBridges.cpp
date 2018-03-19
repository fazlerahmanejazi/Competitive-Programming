bool bridge[1005][1005] ;
vvi adj ;
vb visit ;
vi parent, low, disc, path ;

void init()
  {
    memset(bridge, 0, sizeof bridge) ;
    adj.resize(n+1) ; parent.resize(n+1) ;
    disc.resize(n+1) ; low.resize(n+1) ;
    visit.assign(n+1, false) ;
  }

void findBridges(int u)
  {
    visit[u]=true ;
    disc[u]=low[u]=++T ;
    for(auto v:adj[u])
      if(!visit[v])
        {
          parent[v]=u ;
          findBridges(v) ;
          low[u]=min(low[u], low[v]) ;
          if(low[v]>disc[u]) bridge[u][v]=bridge[v][u]=true ;
        }
      else if(v!=parent[u]) low[u]=min(low[u], disc[v]) ;
  }
