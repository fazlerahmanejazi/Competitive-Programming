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

const int N=200000 ;

template<class T> struct DSU
  {
    map<T, T> par ;
    T comp_sz=0 ; //initial component size
    T get(T u)
      {
        if(par.find(u)==par.end()) return u ;
        return par[u]=get(par[u]) ;
      }
    void unite(T x, T y)
      {
        T X=get(x), Y=get(y) ;
        if(X==Y) return ;
        par[Y]=X ;
        --comp_sz ;
      }
  } ;

int n, k, u, v, x, ans[N] ;
vpii edges, currEdges[N] ;
vvi adj ;
DSU<int> G[N] ;

void dfs(int u)
  {
    G[u].unite(edges[u].fi, edges[u].se) ;
    currEdges[u].pb(edges[u]) ;
    for(auto v:adj[u])
      {
        dfs(v) ;
        if(currEdges[u].size()<currEdges[v].size()) swap(G[u], G[v]), swap(currEdges[u], currEdges[v]) ;
        for(auto &i:currEdges[v]) currEdges[u].pb(i), G[u].unite(i.fi, i.se) ;
      }
    ans[u]=G[u].comp_sz ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    for(int i=1 ; i<=n ; i++) G[i].comp_sz=k ;
    adj.resize(n+1) ;
    edges.resize(n+1) ;
    for(int i=2 ; i<=n ; i++) cin>> x, adj[x].pb(i) ;
    for(int i=1 ; i<=n ; i++) cin>> edges[i].fi >> edges[i].se ;
    dfs(1) ;
    for(int i=1 ; i<=n ; i++) cout<< ans[i] << endl ;
  }
