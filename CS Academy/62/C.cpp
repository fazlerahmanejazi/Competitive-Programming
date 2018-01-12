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

int n, m, q, u, v, x, s, e, T ;
bool bridge[1005][1005] ;
vvi adj ;
vb visit ;
vi parent, low, disc, path, temp ;

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

void dfs(int u)
  {
    temp.pb(u) ;
    visit[u]=true ;
    if(u==e) path=temp ;
    for(auto v:adj[u]) if(!visit[v]) dfs(v) ;
    temp.pop_back() ;
  }

bool query()
  {
    if(!visit[e]) return false ;
    for(int i=0 ; i<path.size()-1 ; i++)
      {
        u=path[i] ; v=path[i+1] ;
        if(!bridge[u][v]) return false ;
      }
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> q ;
    init() ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    for(int i=1 ; i<=n ; i++) if(!visit[i]) findBridges(i) ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> s >> e ;
        visit.assign(n+1, false) ;
        dfs(s) ;
        if(query()) cout<< 1 << endl ;
        else cout<< 0 << endl ;
      }
  }
