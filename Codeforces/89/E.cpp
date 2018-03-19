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

int n, m, u, v, x, T ;
bool bridge ;
set<pii> edges ;
vi parent, low, disc, path ;
vvi adj ;
vb visit ;

void init()
  {
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
          if(low[v]>disc[u]) bridge=true ;
        }
      else if(v!=parent[u]) low[u]=min(low[u], disc[v]) ;
  }

void dfs(int u, int prev)
  {
    visit[u]=true ;
    for(auto v:adj[u])
      if(!visit[v])
        {
          cout<< u << " " << v << endl ;
          edges.erase(mp(min(u, v), max(u, v))) ;
          dfs(v, u) ;
        }
      else if(v!=prev && edges.find(mp(min(u, v), max(u, v)))!=edges.end())
        {
          cout<< u << " " << v << endl ;
          edges.erase(mp(min(u, v), max(u, v))) ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    init() ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
        edges.insert(mp(min(u, v), max(u, v))) ;
      }
    findBridges(1) ;
    if(bridge) cout<< 0 ;
    else
      {
        visit.assign(n+1, false) ;
        dfs(1, -1) ;
        for(auto p:edges) cout<< p.fi << " " << p.se << endl ;
      }
  }
