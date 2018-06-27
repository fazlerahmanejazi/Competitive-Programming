#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
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

int n, m, u, v, x, C, T, diameter ;
vvi tree ;
vector<vpii> adj ;
vb visit, bridge ;
vi parent, low, disc, path, component, f, g ;

void init()
  {
    tree.resize(n+1) ; adj.resize(n+1) ; parent.resize(n+1) ;
    disc.resize(n+1) ; low.resize(n+1) ; f.resize(n+1) ; g.resize(n+1) ;
    component.assign(n+1, 0) ; visit.assign(n+1, false) ;
    bridge.assign(m+1, false) ;
  }

void findBridges(int u)
  {
    visit[u]=true ;
    disc[u]=low[u]=++T ;
    for(auto v:adj[u])
      if(!visit[v.fi])
        {
          parent[v.fi]=u ;
          findBridges(v.fi) ;
          low[u]=min(low[u], low[v.fi]) ;
          if(low[v.fi]>disc[u]) bridge[v.se]=true ;
        }
      else if(v.fi!=parent[u]) low[u]=min(low[u], disc[v.fi]) ;
  }

void dfs(int u)
  {
    component[u]=C ;
    for(auto v:adj[u]) if(!component[v.fi] && !bridge[v.se]) dfs(v.fi) ;
  }

void build(int u)
  {
    visit[u]=true ;
    for(auto v:adj[u])
      if(!visit[v.fi])
        {
          build(v.fi) ;
          if(bridge[v.se])
            {
              tree[component[u]].pb(component[v.fi]) ;
              tree[component[v.fi]].pb(component[u]) ;
            }
        }
  }

void findDiameter(int u, int prev)
  {
    vi temp ;
    for(auto v:tree[u])
      if(v!=prev)
        {
          findDiameter(v, u) ;
          temp.pb(f[v]) ;
        }
    sort(all(temp)) ;
    f[u]=g[u]=0 ;
    if(!temp.empty()) f[u]=1+temp.back() ;
    if(temp.size()>=2) g[u]=2+temp.back()+temp[temp.size()-2] ;
    diameter=max(diameter, max(f[u], g[u])) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    init() ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(mp(v, i)) ;
        adj[v].pb(mp(u, i)) ;
      }
    findBridges(1) ;
    for(int i=1 ; i<=n ; i++) if(!component[i]) C++, dfs(i) ;
    visit.assign(n+1, false) ;
    build(1) ;
    findDiameter(1, -1) ;
    cout<< diameter ;
  }
