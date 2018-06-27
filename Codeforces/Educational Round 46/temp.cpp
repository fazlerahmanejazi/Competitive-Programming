
void findDiameter(int u)
  {
    vi temp ;
    for(auto v:tree[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          temp.pb(f[v]) ;
        }
    sort(all(temp)) ;
    f[u]=g[u]=0 ;
    if(!temp.empty()) f[u]+=temp.back() ;
    if(temp.size()>=2) g[u]=2+temp.back()+temp[temp.size()-2] ;
    diameter=max(diameter, max(f[u], g[u])) ;
  }
