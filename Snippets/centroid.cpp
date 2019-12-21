vi find_centroids(vvi &adj)
    {
      vi centroid, sz(n+1) ;
      function<void (int, int)> dfs=[&](int u, int prev)
        {
          sz[u]=1 ;
          bool is_centroid=true ;
          for(auto v:adj[u])
          if(v!=prev)
            {
              dfs(v, u) ;
              sz[u]+=sz[v];
              if(sz[v]>n/2) is_centroid=false ;
            }
          if(n-sz[u]>n/2) is_centroid=false ;
          if(is_centroid) centroid.pb(u) ;
        } ;
      dfs(1, -1) ;
      return centroid ;
    }
