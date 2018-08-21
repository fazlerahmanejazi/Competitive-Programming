#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, u, v, x, far, s, dia, ans, res, minm, ROOT ;
vvi adj ;
vi dist, root, depth ;
bool check ;

void dfs_dia(int u, int prev, int far)
  {
    if(far>dia)
      {
        dia=far ;
        s=u ;
      }
    for(auto v:adj[u])
      if(v!=prev)
        {
          dist[v]=max(dist[v], far+1) ;
          dfs_dia(v, u, far+1) ;
        }
  }

void dfs(int u, int prev)
  {
    set<int> d ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          depth[u]=max(1+depth[v], depth[u]) ;
        }
    for(auto v:adj[u])
      if(v!=prev)
        d.insert(depth[v]) ;
    if(d.size()>=3) check=false ;
    else if(d.size()==2 && u!=ROOT) check=false ;
    else if(u==ROOT && check)
      {
        dia=0 ;
        for(auto x:d)
          dia+=(x+1) ;
        while(!(dia%2)) dia/=2 ;
        res=min(res, dia) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    dist.assign(n+1, 0) ;
    minm=inf ;
    dia=-inf ;
    res=inf ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs_dia(1, -1, 0) ;
    dfs_dia(s, -1, 0) ;
    dfs_dia(s, -1, 0) ;
    for(int i=1 ; i<=n ; i++)
      minm=min(minm, dist[i]) ;
    for(int i=1 ; i<=n ; i++)
      if(dist[i]==minm)
        root.pb(i) ;
    for(int i=0 ; i<root.size() ; i++)
      {
        check=true ;
        depth.assign(n+1, 0) ;
        ROOT=root[i] ;
        dfs(root[i], -1) ;
      }
    if(res==inf) cout<< -1 ;
    else cout<< res ;
  }
