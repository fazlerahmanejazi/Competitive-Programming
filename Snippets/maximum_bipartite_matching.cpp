class maxBipartiteMatching
  {
    vvi &G ;
    public:
    vi match, mark ;
    int max_match, stamp, n ;
    maxBipartiteMatching(vvi &bipartite_graph, int sz): G(bipartite_graph)
      {
        match.assign(sz+1, -1) ;
        mark.assign(sz+1, -1) ;
        n=sz ;
        stamp=0 ;
      }

    bool augmentPath(int u)
      {
        for(auto v:G[u])
          {
            if(mark[v]==stamp) continue ;
            mark[v]=stamp ;
            if(match[v]==-1 || augmentPath(match[v]))
              {
                match[v]=u ;
                return true ;
              }
          }
        return false ;
      }

    int maxMatching()
      {
        max_match=0 ;
        for(int i=1 ; i<=n ; i++)
          {
            stamp++ ;
            if(augmentPath(i)) max_match++ ;
          }
        return max_match ;
      }
  } ;
