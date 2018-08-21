lli prim()
  {
    lli ans=0 ;
    priority_queue<pair<lli, lli>> pq ;
    visit[1]=true ;
    for(auto v:adj[1]) if(!visit[v.fi]) pq.push(mp(-v.se, -v.fi)) ;
    while(!pq.empty())
      {
        auto x=pq.top() ;
        pq.pop() ;
        w=-x.fi ; u=-x.se ;
        if(!visit[u])
          {
            ans+=w ;
            visit[u]=true ;
            for(auto v:adj[u]) if(!visit[v.fi]) pq.push(mp(-v.se, -v.fi)) ;
          }
      }
    return ans ;
  }
