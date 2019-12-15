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

const int N=200010 ;

int n, q, u, v, w, l, res=0 ;
vector<vpii> adj(N) ;
vi sz(N, 0), par(N) ;
vb del(N, false) ;
vector<vlli> dist(N) ;
vector<map<int, int>> dist_centroid(N) ;

void dfs(int u, int prev, int d, int c)
  {
    dist[c].pb(d) ;
    dist_centroid[c][u]=d ;
    for(auto v:adj[u])
      if(!del[v.fi] && v.fi!=prev)
        dfs(v.fi, u, d+v.se, c) ;
  }

void dfs_sz(int u, int prev)
  {
    sz[u]=1 ;
    for(auto v:adj[u])
      if(!del[v.fi] && v.fi!=prev)
        {
          dfs_sz(v.fi, u) ;
          sz[u]+=sz[v.fi] ;
        }
  }

int find_centroid(int u, int prev, int r)
  {
    for(auto v:adj[u])
      if(!del[v.fi] && v.fi!=prev && sz[v.fi]>r)
        return find_centroid(v.fi, u, r) ;
    return u ;
  }

void decompose(int u, int p)
  {
    dfs_sz(u, u) ;
    int c=find_centroid(u, u, sz[u]/2) ;
    par[c]=p ;
    del[c]=true ;
    dfs(c, c, 0, c) ;
    sort(all(dist[c])) ;
    for(auto v:adj[c]) if(!del[v.fi]) decompose(v.fi, c) ;
  }

int query(int u, int l)
  {
    int res=0 ;
    while(l>0)
      {
        res+=upper_bound(all(dist[u]), l)-dist[u].begin() ;
        if(par[u]==-1) break ;
        l-=dist_centroid[par[u]][u] ;
        u=par[u] ;
      }
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> q ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v >> w ;
        adj[u].pb(mp(v, w)) ;
        adj[v].pb(mp(u, w)) ;
      }
    decompose(1, 1) ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> u >> l ;
        cout<< query(u, l) << endl ;
      }
  }
