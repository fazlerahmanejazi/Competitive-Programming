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

lli n, k, u, v, w, x, res=0 ;
vvi adj(N) ;
vi sz(N, 0) ;
vb is_town(N, false) ;

void dfs(int u, int prev, int d)
  {
    if(is_town[u]) res+=d ;
    for(auto v:adj[u])
      if(v!=prev)
        dfs(v, u, d+1) ;
  }

void dfs_sz(int u, int prev)
  {
    sz[u]=1 ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs_sz(v, u) ;
          sz[u]+=sz[v] ;
        }
  }

int find_centroid(int u, int prev, int r)
  {
    for(auto v:adj[u])
      if(v!=prev && sz[v]>r)
        return find_centroid(v, u, r) ;
    return u ;
  }

int32_t main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    for(int i=1 ; i<=2*k ; i++) cin>> x, is_town[x]=true ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs_sz(1, 1) ;
    int c=find_centroid(1, 1, sz[1]/2) ;
    dfs(c, c, 0) ;
    cout<< res ;
  }
