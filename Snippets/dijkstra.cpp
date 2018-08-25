void dijkstra(int start, vlli &dist, vlli &dp)
  {
    dp.assign(n+1, 0) ;
    dist.assign(n+1, INF) ;
    dist[start]=0 ;
    dp[start]=1 ;
    pq.push(mp(0LL, start)) ;
    while(!pq.empty())
      {
        tie(d, u)=pq.top() ; pq.pop() ;
        if(d>dist[u]) continue ;
        for(auto v:adj[u])
          if(dist[u]+v.se<dist[v.fi])
            {
              dist[v.fi]=dist[u]+v.se ;
              pq.push(mp(dist[v.fi], v.fi)) ;
              dp[v.fi]=dp[u] ;
            }
          else if(dist[u]+v.se==dist[v.fi]) dp[v.fi]=(dp[v.fi]+dp[u])%mod ;
      }
  }
